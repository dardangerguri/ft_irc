#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "colors.h"
# include "Client.hpp"
# include <iostream>
# include <vector>
# include <unordered_set>

class Channel {
	public:
		Channel(std::string name);
		~Channel(void);

		std::string		getName(void);
		std::string		getTopic(void);
		unsigned int	getUserLimit(void);

		void			setTopic(std::string newTopic);
		void			setUserLimit(unsigned int newLimit);

		bool			checkPassword(std::string input);
		bool			validatePassword(char *password);
		bool			isAllowedChannelMode(char mode);
		bool			addMode(char mode);
		bool			delMode(char mode);
		bool			hasMode(char mode);
		bool			userJoin(Client *user);
		bool			userLeave(Client *user);
		bool			userIsOperator(Client *user);
		bool			userMakeOperator(Client *user);
		bool			userRemoveOperator(Client *user);

	private:
		Channel(void);
		Channel(Channel const &copy);
		Channel &operator=(Channel const &copy);

		std::string					name;
		std::string					topic;
		std::string					password;
		unsigned int				userLimit;
		std::vector<Client *>		users;
		std::vector<Client *>		operators;
		std::unordered_set<char>	channelMode;
};

#endif
