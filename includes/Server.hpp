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

class Commands;

class Server {
	public:
		Server(char *port, char *password);
		~Server();

		void	run();

	private:
		Server();
		Server(Server const &copy);
		Server &operator=(Server const &copy);

		unsigned int			port;
		std::string				password;
		int						serverSocket;
		std::vector<pollfd> 	pfds;
		std::vector<Client *>	clients;
		std::vector<Channel *>	channels;
		Commands				*commands;

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
