#include "RPL_YOURHOST.hpp"

RPL_YOURHOST::RPL_YOURHOST(void) {
	command = "002";
}

RPL_YOURHOST::~RPL_YOURHOST(void) {
}

RPL_YOURHOST &RPL_YOURHOST::operator = (RPL_YOURHOST const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_YOURHOST::arranger(Client *source) {
	return (command + " " + source->getNickname() + \
	" :Your host is ft_irc, running version 1.69");
}
