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
	return (command + " " + source->getNickname() + " " + channel->getName() + " :Cannot join channel (+l)");
}
