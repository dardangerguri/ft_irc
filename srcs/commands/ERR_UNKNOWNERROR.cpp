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

std::string ERR_UNKNOWNERROR::arranger(std::string sourceCommand, std::string info, Client *source) {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + sourceCommand + " :" + info);
}
