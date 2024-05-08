#include "ERR_ERRONEUSNICKNAME.hpp"

ERR_ERRONEUSNICKNAME::ERR_ERRONEUSNICKNAME(void) {
	command = "432";
}

ERR_ERRONEUSNICKNAME::~ERR_ERRONEUSNICKNAME(void) {
}

ERR_ERRONEUSNICKNAME &ERR_ERRONEUSNICKNAME::operator = (ERR_ERRONEUSNICKNAME const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_ERRONEUSNICKNAME::arranger(std::string const erroneousNickname, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + erroneousNickname + " :Erroneus nickname");
}
