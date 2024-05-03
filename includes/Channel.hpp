#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "colors.h"
# include "Client.hpp"
# include <iostream>
# include <unordered_set>

class Channel {
	public:
		Channel(std::string name);
		~Channel(void);

		std::string						getName(void);
		std::string						getTopic(void);
		std::string						getTopicAuthor(void);
		std::time_t						getTopicTime(void);
		unsigned int					getUserLimit(void);
		unsigned int					getUserCount(void);
		std::unordered_set<Client *>	getUserList(void);

		void							setTopic(std::string newTopic);
		void							setTopicAuthor(Client *user);
		void							setTopicTime(std::time_t time);
		void							setUserLimit(unsigned int newLimit);

		bool							checkPassword(std::string input);
		bool							validatePassword(std::string password);
		bool							isAllowedChannelMode(char mode);
		bool							addMode(char mode);
		bool							delMode(char mode);
		bool							hasMode(char mode);
		bool							userJoin(Client *user);
		void							userLeave(Client *user);
		bool							userIsJoined(Client *user);
		bool							userIsOperator(Client *user);
		bool							userMakeOperator(Client *user);
		void							userRemoveOperator(Client *user);

	private:
		Channel(void);
		Channel(Channel const &copy);
		Channel &operator=(Channel const &copy);

		std::string						name;
		std::string						topic;
		std::string						topicAuthor;
		std::time_t						topicTime;
		std::string						password;
		unsigned int					userLimit;
		std::unordered_set<Client *>	users;
		std::unordered_set<Client *>	operators;
		std::unordered_set<char>		channelMode;
};

#endif
