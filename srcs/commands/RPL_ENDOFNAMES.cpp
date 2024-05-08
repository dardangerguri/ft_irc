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

std::string const RPL_ENDOFNAMES::arranger(Client *source, Channel *channel) const {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName+ " :End of /NAMES list");
}

std::string const RPL_ENDOFNAMES::arranger(Client *source, std::string const channelName) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + channelName + " :End of /NAMES list");
}
