#ifndef CLIENT_HPP
# define CLIENT_HPP

# define MSG_BUFFER_SIZE 512

# include "colors.h"
# include <iostream>
# include <unordered_set>
# include <vector>

class Channel;

class Client {
	public:
		Client(int socketFd);
		~Client(void);

		void 		addBufferToMsgBuffer(std::string buffer);
		bool		msgCompleted(void);
		bool		isAllowedUserMode(char mode);
		bool		addMode(char mode);
		bool		delMode(char mode);
		bool		hasMode(char mode);
		bool		tryToRegister(void);

		int			getSocketFd(void);
		std::string	getMsgFromBuffer(void);
		std::string	getNickname(void);
		std::string	getUsername(void);
		std::string	getRealname(void);
		bool		getValidPass(void);

		void		setNickname(std::string newNickname);
		void		setUsername(std::string newUsername);
		void		setRealname(std::string newRealname);
		void		setValidPass(void);

	private:
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		int 							socketFd;
		std::string						msgBuffer;
		std::string						nickname;
		std::string						username;
		std::string						realname;
		bool							validPass;
		std::unordered_set<char>		userMode;
		std::vector<Channel *>	joinedChannels;
		std::vector<Channel *>	invitedChannels;
};

# include "Channel.hpp"

#endif
