#include "RPL_NOTOPIC.hpp"

RPL_NOTOPIC::RPL_NOTOPIC(void) {
	command = "331";
}

RPL_NOTOPIC::~RPL_NOTOPIC(void) {
}

RPL_NOTOPIC &RPL_NOTOPIC::operator = (RPL_NOTOPIC const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_NOTOPIC::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() + " :No topic is set");
}
