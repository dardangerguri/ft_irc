#include "RPL_LUSERCLIENT.hpp"

RPL_LUSERCLIENT::RPL_LUSERCLIENT(Commands *c) {
	commands = c;
	command = "251";
}

RPL_LUSERCLIENT::~RPL_LUSERCLIENT(void) {
}

RPL_LUSERCLIENT &RPL_LUSERCLIENT::operator = (RPL_LUSERCLIENT const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_LUSERCLIENT::arranger(Client *source) {
	return (command + " " + source->getNickname() + \
	" :There are " + std::to_string(commands->server->getClientCount()) + \
	" users and 0 invisible on 0 servers");
}
