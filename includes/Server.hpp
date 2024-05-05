#ifndef SERVER_HPP
# define SERVER_HPP

# include "colors.h"
# include "Channel.hpp"
# include "Client.hpp"
# include <iostream>
# include <unistd.h>
# include <string>
# include <sstream>
# include <vector>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <poll.h>
# include <algorithm>
# include <unordered_map>
# include <arpa/inet.h>

class Commands;

class Server {
	public:
		Server(char *port, char *password);
		~Server();

		void			run();
		bool			checkPassword(std::string input);
		bool			nickExists(std::string input);
		unsigned int	getClientCount();
		Channel			*addChannel(std::string channelName);
		void			delChannel(Channel *channel);
		Channel			*getChannel(std::string channelName);
		Client			*getClient(std::string nickname);

	private:
		Server();
		Server(Server const &copy);
		Server &operator=(Server const &copy);

		unsigned int								port;
		std::string									password;
		int											serverSocket;
		std::vector<pollfd> 						pfds;
		std::vector<Client *>						clients;
		std::unordered_map<std::string, Channel *>	channels;
		Commands									*commands;

		void	validatePort(char *port);
		void	validatePassword(char *password);
		void	initListenSocket();
		void	handleNewConnection();
		void	handleClientData(size_t pollFdIndex);
		void	parseMsg(std::string message, Client *client);
		Client	*getClientBySocketFd(int socketFd);
};

# include "Commands.hpp"

#endif
