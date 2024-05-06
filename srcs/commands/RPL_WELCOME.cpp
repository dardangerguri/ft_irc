#include "RPL_WELCOME.hpp"

RPL_WELCOME::RPL_WELCOME(void) {
	command = "001";
}

RPL_WELCOME::~RPL_WELCOME(void) {
}

RPL_WELCOME &RPL_WELCOME::operator = (RPL_WELCOME const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_WELCOME::arranger(Client *source) {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :Welcome to the IRC BOYS Network, " + nickname + "!");
}
