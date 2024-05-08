#include "RPL_NAMREPLY.hpp"

RPL_NAMREPLY::RPL_NAMREPLY(void) {
	command = "353";
}

RPL_NAMREPLY::~RPL_NAMREPLY(void) {
}

RPL_NAMREPLY &RPL_NAMREPLY::operator = (RPL_NAMREPLY const &copy) {
	(void)copy;
	return (*this);
}

// Only send one user at the time, so we don't have to worry about message getting too long
std::string RPL_NAMREPLY::arranger(Client *source, Channel *channel, Client *user) const {
	std::string	nickname;
	std::string	channelName;
	std::string	userNickname;
	std::string	userPrefix;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();
	if (user) {
		userNickname = user->getNickname();
		if (channel->userIsOperator(user))
			userPrefix = "@";
	}

	return (command + " " + nickname+ " = " + channelName + " :" + userPrefix + userNickname);
}
