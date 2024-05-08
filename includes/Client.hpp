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
		Client(int const socketFd);
		~Client(void);

		void 												addBufferToMsgBuffer(std::string const buffer);
		bool 												msgCompleted(void) const;
		bool 												isAllowedUserMode(char const mode) const;
		bool 												addMode(char const mode);
		bool 												delMode(char const mode);
		bool 												hasMode(char const mode) const;
		bool 												tryToRegister(void);

		char const											*getIp(void);
		int			 										getSocketFd(void) const;
		std::string const									getMsgFromBuffer(void);
		std::string const									getNickname(void) const;
		std::string const									getUsername(void) const;
		std::string const									getRealname(void) const;
		bool 												getValidPass(void) const;
		std::unordered_map<std::string, Channel *> const	getJoinedChannels(void) const;

		void												setIp(char *newIp);
		void												setNickname(std::string const newNickname);
		void												setUsername(std::string const newUsername);
		void												setRealname(std::string const newRealname);
		void												setValidPass(void);

		bool												joinChannel(Channel *channel);
		void												leaveChannel(Channel *channel);
		bool												inviteToChannel(Channel *channel);
		void												removeInviteToChannel(Channel *channel);
		bool												inChannel(Channel *channel) const;
		bool												isInvitedToChannel(Channel *channel) const;

	private:
		Client(void);
		Client(Client const &copy);
		Client &operator=(Client const &copy);

		char										*ip;
		const int									socketFd;
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
