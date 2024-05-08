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

std::string RPL_ENDOFNAMES::arranger(Client *source, Channel *channel) const {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName+ " :End of /NAMES list");
}

std::string RPL_ENDOFNAMES::arranger(Client *source, std::string const channelName) const {
	return (command + " " + source->getNickname() + " " + channelName + " :End of /NAMES list");
}
