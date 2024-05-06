#include "ERR_USERONCHANNEL.hpp"

ERR_USERONCHANNEL::ERR_USERONCHANNEL(void) {
	command = "443";
}

ERR_USERONCHANNEL::~ERR_USERONCHANNEL(void) {
}

ERR_USERONCHANNEL &ERR_USERONCHANNEL::operator = (ERR_USERONCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_USERONCHANNEL::arranger(Client *source, Client *target, Channel *channel) {
	std::string	nickname;
	std::string	targetNickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (target)
		targetNickname = target->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + targetNickname + " " + channelName + " :is already on channel");
}
