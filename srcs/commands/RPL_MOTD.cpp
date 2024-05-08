#include "RPL_MOTD.hpp"

RPL_MOTD::RPL_MOTD(void) {
	command = "372";
}

RPL_MOTD::~RPL_MOTD(void) {
}

RPL_MOTD &RPL_MOTD::operator = (RPL_MOTD const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_MOTD::arranger(Client *source, std::string const motdLine) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :" + motdLine);
}
