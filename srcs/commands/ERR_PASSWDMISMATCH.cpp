#include "ERR_PASSWDMISMATCH.hpp"

ERR_PASSWDMISMATCH::ERR_PASSWDMISMATCH(void) {
	command = "464";
}

ERR_PASSWDMISMATCH::~ERR_PASSWDMISMATCH(void) {
}

ERR_PASSWDMISMATCH &ERR_PASSWDMISMATCH::operator = (ERR_PASSWDMISMATCH const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_PASSWDMISMATCH::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :Password incorrect");
}
