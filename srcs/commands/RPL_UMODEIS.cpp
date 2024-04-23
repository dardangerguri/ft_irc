#include "RPL_UMODEIS.hpp"

RPL_UMODEIS::RPL_UMODEIS(void) {
	command = "221";
}

RPL_UMODEIS::~RPL_UMODEIS(void) {
}

RPL_UMODEIS &RPL_UMODEIS::operator = (RPL_UMODEIS const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_UMODEIS::arranger(Client *source) {
	std::string modes = "";
	if (source->hasMode('r'))
		modes += "r";
	if (source->hasMode('o'))
		modes += "o";
	return (command + " " + source->getNickname() + " " + modes);
}
