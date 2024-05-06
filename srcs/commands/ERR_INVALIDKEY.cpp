#include "ERR_INVALIDKEY.hpp"

ERR_INVALIDKEY::ERR_INVALIDKEY(void) {
	command = "525";
}

ERR_INVALIDKEY::~ERR_INVALIDKEY(void) {
}

ERR_INVALIDKEY &ERR_INVALIDKEY::operator = (ERR_INVALIDKEY const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_INVALIDKEY::arranger(Client *source, Channel *channel) {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :Key is not well-formed");
}
