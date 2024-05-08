#include "ERR_UNKNOWNMODE.hpp"

ERR_UNKNOWNMODE::ERR_UNKNOWNMODE(void) {
	command = "472";
}

ERR_UNKNOWNMODE::~ERR_UNKNOWNMODE(void) {
}

ERR_UNKNOWNMODE &ERR_UNKNOWNMODE::operator = (ERR_UNKNOWNMODE const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_UNKNOWNMODE::arranger(char const mode, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + mode + " :is unknown mode char to me");
}
