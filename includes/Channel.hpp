#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "colors.h"
# include "Client.hpp"
# include <iostream>
# include <unordered_set>

class Channel {
	public:
		Channel(std::string const name);
		~Channel(void);

		std::string						getName(void) const;
		std::string						getTopic(void) const;
		std::string						getTopicAuthor(void) const;
		std::time_t						getTopicTime(void) const;
		unsigned int					getUserLimit(void) const;
		unsigned int					getUserCount(void) const;
		std::unordered_set<Client *>	getUserList(void) const;
		std::string						getPassword(void) const;

		void							setTopic(std::string const newTopic);
		void							setTopicAuthor(Client *user);
		void							setTopicTime(std::time_t const time);
		void							setUserLimit(unsigned int const newLimit);
		void							setPassword(std::string const newPassword);

		bool							checkPassword(std::string const input) const;
		bool							validatePassword(std::string const password) const;
		bool							isAllowedChannelMode(char const mode) const;
		bool							addMode(char const mode);
		bool							delMode(char const mode);
		bool							hasMode(char const mode) const;
		bool							userJoin(Client *user);
		void							userLeave(Client *user);
		bool							userIsJoined(Client *user) const;
		bool							userIsOperator(Client *user) const;
		bool							userMakeOperator(Client *user);
		void							userRemoveOperator(Client *user);

	private:
		Channel(void);
		Channel(Channel const &copy);
		Channel &operator=(Channel const &copy);

		const std::string				name;
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
