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

std::string const RPL_LUSERCLIENT::arranger(Client *source) const {
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
	return (command + " " + nickname + " :There are " + clientCount + " users and 0 invisible on 0 servers");
}
