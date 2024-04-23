#include "RPL_LUSERME.hpp"

RPL_LUSERME::RPL_LUSERME(Commands *c) {
	commands = c;
	command = "255";
}

RPL_LUSERME::~RPL_LUSERME(void) {
}

RPL_LUSERME &RPL_LUSERME::operator = (RPL_LUSERME const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_LUSERME::arranger(Client *source) {
	return (command + " " + source->getNickname() + \
	" :I have " + std::to_string(commands->server->getClientCount()) + \
	" clients and 0 servers");
}
