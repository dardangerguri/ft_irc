#include "Client.hpp"

// FIXME catch all exceptions here!!!!!!!!!!

Client::Client(int socketFd) {
	this->socketFd = socketFd;
}

Client::~Client() {
	for (std::pair<std::string, Channel *> chan : joinedChannels) {
		chan.second->userLeave(this);
	}
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
	// +i : invisible user mode
	// +O : local oper user mode
	// +w : WALLOPS user mode

	std::unordered_set<char> supportedModes = {'o', 'r', 'i', 'O', 'w'};

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
	std::string message;

	size_t pos = this->msgBuffer.find("\r\n");
	if (pos != std::string::npos) {
		message = this->msgBuffer.substr(0, pos);
		this->msgBuffer = this->msgBuffer.substr(pos + 2);
	}
	else
		return ("");
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

bool Client::getValidPass(void) {
	return (validPass);
}

std::unordered_map<std::string, Channel *> Client::getJoinedChannels(void) {
	return (joinedChannels);
}

void Client::setNickname(std::string newNickname) {
	this->nickname = newNickname;
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

bool Client::joinChannel(Channel *channel) {
	if (!channel)
		return (false);
	try {
		joinedChannels.insert({channel->getName(), channel});
	}
	catch (...) {
		return (false);
	}
	if (!channel->userIsJoined(this)) {
		if (!channel->userJoin(this)) {
			joinedChannels.erase(channel->getName());
			return (false);
		}
	}
	invitedChannels.erase(channel->getName());
	return (true);
}

void Client::leaveChannel(Channel *channel) {
	if (channel) {
		joinedChannels.erase(channel->getName());
		if (channel->userIsJoined(this))
			channel->userLeave(this);
	}
}

bool Client::inviteToChannel(Channel *channel) {
	if (!channel)
		return (false);
	try {
		invitedChannels.insert({channel->getName(), channel});
	}
	catch (...) {
		return (false);
	}
	return (true);
}

void Client::removeInviteToChannel(Channel *channel) {
	if (channel)
		invitedChannels.erase(channel->getName());
}


bool Client::inChannel(Channel *channel) {
	if (!channel)
		return (false);
	if (joinedChannels.find(channel->getName()) != joinedChannels.end())
		return (true);
	return (false);
}

bool Client::isInvitedToChannel(Channel *channel) {
	if (!channel)
		return (false);
	if (invitedChannels.find(channel->getName()) != invitedChannels.end())
		return (true);
	return (false);
}
