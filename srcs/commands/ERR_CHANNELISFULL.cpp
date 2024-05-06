#include "ERR_CHANNELISFULL.hpp"

ERR_CHANNELISFULL::ERR_CHANNELISFULL(void) {
	command = "471";
}

ERR_CHANNELISFULL::~ERR_CHANNELISFULL(void) {
}

ERR_CHANNELISFULL &ERR_CHANNELISFULL::operator = (ERR_CHANNELISFULL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_CHANNELISFULL::arranger(Client *source, Channel *channel) {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :Cannot join channel (+l)");
}
