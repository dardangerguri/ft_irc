#include "Server.hpp"

Server::Server(char *port, char *password) {
	validatePort(port);
	validatePassword(password);
	initListenSocket();

	try {
		commands = new Commands(this);
	}
	catch (std::bad_alloc) {
		throw std::runtime_error("Memory allocation for commands object failed!");
	}
}

Server::~Server() {
	std::for_each(clients.begin(), clients.end(), [](Client *c){delete c;});
	clients.clear();

	std::for_each(channels.begin(), channels.end(), [](std::pair<std::string, Channel *>c){delete c.second;});
	channels.clear();

	delete commands;
	pfds.clear();
}

void	Server::validatePort(char *port) {
	for (size_t i = 0; i < strlen(port); ++i) {
		if (!std::isdigit(port[i]))
			throw std::runtime_error("Error: Port must be a number!");
	}
	int p = std::atoi(port);
	if (p < 0 || p > 65535)
		throw std::runtime_error("Error: Port must be between 0 and 65536!");
	this->port = p;
}

void	Server::validatePassword(char *password) {
	if (password[0]	== '\0')
		throw std::runtime_error("Error: Password cannot be empty!");
	if (std::string(password).find(' ') != std::string::npos)
		throw std::runtime_error("Error: Password cannot contain whitespace!");
	this->password = password;
}

bool Server::checkPassword(std::string input) {
	if (input == password)
		return (true);
	return (false);
}

bool Server::nickExists(std::string input) {
	for (size_t i = 0; i < clients.size(); ++i) {
		if (clients[i]->getNickname() == input)
			return (true);
	}
	return (false);
}

unsigned int Server::getClientCount() {
	return (clients.size());
}

Channel *Server::addChannel(std::string channelName) {
	Channel *newChannel;

	try {
		try {
			newChannel = new Channel(channelName);
		}
		catch (...) {
			return (nullptr);
		}
		channels.insert({channelName, newChannel});
		return (newChannel);
	}
	catch (...) {
		delete newChannel;
		return (nullptr);
	}
}

void Server::delChannel(Channel *channel) {
	std::unordered_map<std::string, Channel *>::iterator chanIter;

	if (channel) {
		chanIter = channels.find(channel->getName());
		if (chanIter != channels.end())
			channels.erase(chanIter);
		delete channel;
	}
}

Channel *Server::getChannel(std::string channelName) {
	if (channels.find(channelName) != channels.end())
		return (channels[channelName]);
	return (nullptr);
}

Client *Server::getClient(std::string nickname) {
	for (size_t i = 0; i < clients.size(); ++i) {
		if (clients[i]->getNickname() == nickname)
			return (clients[i]);
	}
	return (nullptr);
}

void	Server::initListenSocket() {
	// Creating socket
	this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->serverSocket == -1)
		throw std::runtime_error("Could not create server socket!");

	// Set socket options for reusing addresses and ports
	int yes = 1;
	if (setsockopt(this->serverSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof yes) == -1)
		throw std::runtime_error("Could not set socket options!");

	// Specifying the address
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(this->port);

	// Binding socket
	if (bind(this->serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0)
		throw std::runtime_error("Error binding server socket!");

	// Listening to the assigned socket
	if (listen(this->serverSocket, 5) < 0)
		throw std::runtime_error("Error listening on server socket!");

	// Add server socket to the list of file descriptors to be polled
	pollfd serverPollfd;
	serverPollfd.fd = this->serverSocket;
	serverPollfd.events = POLLIN;
	pfds.push_back(serverPollfd);
}

void	Server::run() {
	while (true) {
		// Poll for events on all sockets

		if (poll(pfds.data(), pfds.size(), 5000) == -1)
			std::cerr << RED << "poll() failed!" << RESET << std::endl;
		else
		{
			// Iterate over all sockets, and handle events
			for (size_t i = 0; i < pfds.size(); ++i) {
				if (pfds[i].revents & POLLIN) {
					if (pfds[i].fd == serverSocket) {
						handleNewConnection();
					}
					else {
						handleClientData(i);
					}
				}
			}
		}
	}
	// Close the server socket when done
	close(serverSocket);
}

void Server::handleNewConnection() {
	// Accept the new client connection
	struct sockaddr_storage clientAddress;
	socklen_t clientAddressSize = sizeof(clientAddress);
	int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressSize);

	Client *newClient;

	try {
		if (clientSocket == -1)
			throw std::runtime_error("Could not accept client connection!");
		newClient = new Client(clientSocket);

		try {
			clients.push_back(newClient);
		}
		catch (std::bad_alloc) {
			delete newClient;
			throw std::runtime_error("Memory allocation for new user object failed!");
		}
	}
	catch (std::exception &e) {
		std::cerr << RED << "Error creating new client: " << e.what() << RESET << std::endl;
		return ;
	}

	try {
		// Add the client socket to the list of polled file descriptors
		pollfd clientPollfd;
		clientPollfd.fd = clientSocket;
		clientPollfd.events = POLLIN;
		pfds.push_back(clientPollfd);
	}
	catch (std::exception &e) {
		std::cerr << RED << "Error creating new client: " << e.what() << RESET << std::endl;
		delete newClient;
		return ;
	}

	// Print the new client connection
	std::cout << GREEN << "New client connected: " << clientSocket << RESET << std::endl;
}

void Server::handleClientData(size_t pollFdIndex) {
	// get client from the list of clients based on the pollFdIndex
	Client *client = getClientBySocketFd(pfds[pollFdIndex].fd);
	if (!client)
		return ;

	// Receive data from the client
	char buffer[512] = { 0 };
	int nbytes = recv(pfds[pollFdIndex].fd, buffer, sizeof(buffer) - 1, 0);
	if (nbytes <= 0) {
		// Print the client disconnection
		std::cout << RED << "Client disconnected: " << pfds[pollFdIndex].fd << RESET << std::endl;

		for (std::pair<std::string, Channel *> chanPair : client->getJoinedChannels()) {
			commands->sendCommand(commands->quit->arranger("disconnected"), client, chanPair.second, client);
			chanPair.second->userLeave(client);
			if (chanPair.second->getUserCount() == 0)
				delChannel(chanPair.second);
		}

		close(pfds[pollFdIndex].fd);
		pfds.erase(pfds.begin() + pollFdIndex);

		clients.erase(std::remove(clients.begin(), clients.end(), client), clients.end());
		delete client;
		return ;
	}
	client->addBufferToMsgBuffer(buffer);
	while (client->msgCompleted()) {
		parseMsg(client->getMsgFromBuffer(), client);
	}
}

// Checks if the command is valid and checks if it can find in the commandList
void Server::parseMsg(std::string message, Client *client) {
	//Debug
	std::cerr << RED "Received: " RESET +  message << std::endl;

	if (message.empty() || !client)
		return ;

	// make sure we only have ASCII SPACEs and no other whitespace
	for (char c : message) {
		if (std::isspace(c) && c != ' ') {
			std::cerr << "Error: Found other whitespace characters!" << std::endl;
			return ;
		}
	}

	// split command from parameters
	std::stringstream	ss(message);
	std::string			command;
	std::string			restOfMessage;
	ss >> command;
	std::getline(ss, restOfMessage);

	// remove spaces from the beginning of parameters
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos)
		restOfMessage = restOfMessage.substr(pos);
	else
		restOfMessage = "";

	for (size_t i = 0; i < command.size(); i++)
		command[i] = std::toupper(command[i]);

	std::shared_ptr<ACommand> commandPtr = commands->getCommandFromList(command);
	if (commandPtr) {
		if (commandPtr->getRequireRegistration() && !client->hasMode('r'))
			commands->sendCommand(commands->errNotRegistered->arranger(client), client);
		else
			commandPtr->handleCommand(restOfMessage, client);
	}
	else {
		commands->sendCommand(commands->errUnknownCommand->arranger(command, client), client);
	}
}

Client *Server::getClientBySocketFd(int socketFd) {
	for (size_t i = 0; i < clients.size(); ++i) {
		if (clients[i]->getSocketFd() == socketFd)
			return (clients[i]);
	}
	return (nullptr);
}
