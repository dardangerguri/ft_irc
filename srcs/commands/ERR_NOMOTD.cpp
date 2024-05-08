#include "ERR_NOMOTD.hpp"

ERR_NOMOTD::ERR_NOMOTD(void) {
	command = "422";
}

ERR_NOMOTD::~ERR_NOMOTD(void) {
}

ERR_NOMOTD &ERR_NOMOTD::operator = (ERR_NOMOTD const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_NOMOTD::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :MOTD File is missing");
}
