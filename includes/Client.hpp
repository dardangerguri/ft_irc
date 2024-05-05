#ifndef CLIENT_HPP
# define CLIENT_HPP

# define MSG_BUFFER_SIZE 512

# include "colors.h"
# include <iostream>
# include <unordered_set>
# include <vector>
# include <unordered_map>

class Channel;

class Client {
	public:
		Client(int socketFd);
		~Client(void);

		void 										addBufferToMsgBuffer(std::string buffer);
		bool 										msgCompleted(void);
		bool 										isAllowedUserMode(char mode);
		bool 										addMode(char mode);
		bool 										delMode(char mode);
		bool 										hasMode(char mode);
		bool 										tryToRegister(void);

		char										*getIp(void);
		int 										getSocketFd(void);
		std::string									getMsgFromBuffer(void);
		std::string									getNickname(void);
		std::string									getUsername(void);
		std::string									getRealname(void);
		bool 										getValidPass(void);
		std::unordered_map<std::string, Channel *>	getJoinedChannels(void);

		void										setIp(char *newIp);
		void										setNickname(std::string newNickname);
		void										setUsername(std::string newUsername);
		void										setRealname(std::string newRealname);
		void										setValidPass(void);

		bool										joinChannel(Channel *channel);
		void										leaveChannel(Channel *channel);
		bool										inviteToChannel(Channel *channel);
		void										removeInviteToChannel(Channel *channel);
		bool										inChannel(Channel *channel);
		bool										isInvitedToChannel(Channel *channel);

	private:
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		char										*ip;
		int 										socketFd;
		std::string									msgBuffer;
		std::string									nickname;
		std::string									username;
		std::string									realname;
		bool										validPass;
		std::unordered_set<char>					userMode;
		std::unordered_map<std::string, Channel *>	joinedChannels;
		std::unordered_map<std::string, Channel *>	invitedChannels;
};

# include "Channel.hpp"

#endif
