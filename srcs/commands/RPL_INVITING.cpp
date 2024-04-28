#include "RPL_INVITING.hpp"

RPL_INVITING::RPL_INVITING(void) {
	command = "341";
}

RPL_INVITING::~RPL_INVITING(void) {
}

RPL_INVITING &RPL_INVITING::operator = (RPL_INVITING const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_INVITING::arranger(Client *source, Client *target, Channel *channel) {
	return (command + " " + source->getNickname() + " " + target->getNickname() + " " + channel->getName());
}
