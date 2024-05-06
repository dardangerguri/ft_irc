#include "RPL_CREATED.hpp"

RPL_CREATED::RPL_CREATED(void) {
	command = "003";
}

RPL_CREATED::~RPL_CREATED(void) {
}

RPL_CREATED &RPL_CREATED::operator = (RPL_CREATED const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_CREATED::arranger(Client *source) {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :This server was created 6 million years ago");
}
