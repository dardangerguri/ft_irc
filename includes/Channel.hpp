#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "colors.h"
//#include "Client.hpp"
# include <iostream>
//#include <vector>

class Channel {
	public:
		Channel(void);
		~Channel(void);

		std::string getChannelName(void);

	private:
		Channel(Channel const &copy);
		Channel &operator=(Channel const &copy);

		std::string				name;
		int						id; // not sure if we are gonna keep this!
		std::string				topic;
		std::string				mode;
		// std::vector<Client *>	clients;
		// std::vector<Client *>	operators;
};

#endif
