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
	return (command + " " + source->getNickname() + " " + channel->getName() + " :Key is not well-formed");
}
