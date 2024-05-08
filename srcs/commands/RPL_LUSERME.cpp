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

std::string RPL_LUSERME::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	std::string clientCount;
	try {
		clientCount = std::to_string(commands->server->getClientCount());
	}
	catch (...) {
		clientCount = "0";
	}
	return (command + " " + nickname + " :I have " + clientCount + " clients and 0 servers");
}
