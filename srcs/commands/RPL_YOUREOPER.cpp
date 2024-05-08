#include "RPL_YOUREOPER.hpp"

RPL_YOUREOPER::RPL_YOUREOPER(void) {
	command = "381";
}

RPL_YOUREOPER::~RPL_YOUREOPER(void) {
}

RPL_YOUREOPER &RPL_YOUREOPER::operator = (RPL_YOUREOPER const &copy) {
	(void)copy;
	return (*this);
}

std::string const RPL_YOUREOPER::arranger(Client *source) const {
	std::string nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :You are now an IRC operator");
}
