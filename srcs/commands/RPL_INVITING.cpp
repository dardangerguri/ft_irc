#include "RPL_INVITING.hpp"

RPL_INVITING::RPL_INVITING(void) {
	command = "341";
}

RPL_INVITING::~RPL_INVITING(void) {
}

RPL_INVITING &RPL_INVITING::operator = (RPL_INVITING const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_INVITING::arranger(Client *source, Client *target, Channel *channel) const {
	std::string	nickname;
	std::string targetNickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (target)
		targetNickname = target->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + targetNickname + " " + channelName);
}
