#include "RPL_ENDOFNAMES.hpp"

RPL_ENDOFNAMES::RPL_ENDOFNAMES(void) {
	command = "366";
}

RPL_ENDOFNAMES::~RPL_ENDOFNAMES(void) {
}

RPL_ENDOFNAMES &RPL_ENDOFNAMES::operator = (RPL_ENDOFNAMES const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_ENDOFNAMES::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() + " :End of /NAMES list");
}

std::string RPL_ENDOFNAMES::arranger(Client *source, std::string channelName) {
	return (command + " " + source->getNickname() + " " + channelName + " :End of /NAMES list");
}
