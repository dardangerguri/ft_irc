#include "ERR_NOTONCHANNEL.hpp"

ERR_NOTONCHANNEL::ERR_NOTONCHANNEL(void) {
	command = "442";
}

ERR_NOTONCHANNEL::~ERR_NOTONCHANNEL(void) {
}

ERR_NOTONCHANNEL &ERR_NOTONCHANNEL::operator = (ERR_NOTONCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOTONCHANNEL::arranger(Client *source, Channel *channel) {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :You're not on that channel");
}
