#include "ERR_BADCHANNELKEY.hpp"

ERR_BADCHANNELKEY::ERR_BADCHANNELKEY(void) {
	command = "475";
}

ERR_BADCHANNELKEY::~ERR_BADCHANNELKEY(void) {
}

ERR_BADCHANNELKEY &ERR_BADCHANNELKEY::operator = (ERR_BADCHANNELKEY const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_BADCHANNELKEY::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() + " :Cannot join channel (+k)");
}
