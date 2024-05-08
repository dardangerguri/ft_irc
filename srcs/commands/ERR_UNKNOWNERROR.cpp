#include "ERR_UNKNOWNERROR.hpp"

ERR_UNKNOWNERROR::ERR_UNKNOWNERROR(void) {
	command = "400";
}

ERR_UNKNOWNERROR::~ERR_UNKNOWNERROR(void) {
}

ERR_UNKNOWNERROR &ERR_UNKNOWNERROR::operator = (ERR_UNKNOWNERROR const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_UNKNOWNERROR::arranger(std::string const sourceCommand, std::string const info, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + sourceCommand + " :" + info);
}
