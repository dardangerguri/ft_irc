#include "Client.hpp"

// FIXME catch all exceptions here!!!!!!!!!!

Client::Client(int socketFd) {
	this->socketFd = socketFd;
}

Client::~Client() {
}

void Client::addBufferToMsgBuffer(std::string buffer) {
	// FIXME: Maybe better handling for overflow???
	// if the message becomes longer than MSG_BUFFER_SIZE
	if (this->msgBuffer.length() + buffer.length() > MSG_BUFFER_SIZE) {
		// only accepts the message for the defined MSG_BUFFER_SIZE
		this->msgBuffer += buffer.substr(0, MSG_BUFFER_SIZE - this->msgBuffer.length());
		//finds the last occurance of the \r\n, if that exists
		size_t found = this->msgBuffer.rfind("\r\n");
		// if \r\n exists it removes the rest of the message
		if (found != std::string::npos)
			this->msgBuffer = this->msgBuffer.substr(0, found);
		// if it is longer than MSG_BUFFER_SIZE and no \r\n it clears the messageBuffer!
		else
			this->msgBuffer.clear();
		std::cout << RED << "Error: Message buffer is full!" << std::endl;
	}
	else
		this->msgBuffer += buffer;
}

bool Client::msgCompleted(void) {
	if (this->msgBuffer.find("\r\n") != std::string::npos)
		return (true);
	return (false);
}

bool Client::isAllowedUserMode(char mode) {
	// Modes supported by this server:
	// +o : oper user mode
	// +r : registered user mode
	// Other modes supported by IRC standard:
	// +i : invisible user mode
	// +O : local oper user mode
	// +w : WALLOPS user mode

	std::unordered_set<char> supportedModes = {'o', 'r'};

	if (supportedModes.find(mode) != supportedModes.end())
		return (true);
	return (false);
}

bool Client::addMode(char mode) {
	if (!isAllowedUserMode(mode))
		return (false);
	try {
		userMode.insert(mode);
		return (true);
	}
	catch (...) {
		return (false);
	}
}

bool Client::delMode(char mode) {
	if (!isAllowedUserMode(mode))
		return (false);
	userMode.erase(mode);
	return (true);
}

bool Client::hasMode(char mode) {
	if (userMode.find(mode) != userMode.end())
		return (true);
	return (false);
}

bool Client::tryToRegister(void) {
	if (this->hasMode('r'))
		return (false);
	if (!username.empty() && !nickname.empty() && validPass) {
		this->addMode('r');
		return (true);
	}
	return (false);
}

int Client::getSocketFd(void) {
	return (this->socketFd);
}

std::string Client::getMsgFromBuffer(void) {
	std::string message = this->msgBuffer.substr(0, this->msgBuffer.find("\r\n"));
	this->msgBuffer = this->msgBuffer.substr(this->msgBuffer.find("\r\n") + 2);
	return (message);
}

std::string Client::getNickname(void) {
	return (nickname);
}

std::string Client::getUsername(void) {
	return (username);
}

std::string Client::getRealname(void) {
	return (realname);
}

void Client::setNickname(std::string newNickname) {
	this->nickname = newNickname;
	//FIXME inform other clients about the change
}

void Client::setUsername(std::string newUsername) {
	this->username = newUsername;
}

void Client::setRealname(std::string newRealname) {
	this->realname = newRealname;
}

void Client::setValidPass(void) {
	this->validPass = true;
}
