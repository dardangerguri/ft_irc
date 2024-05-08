#include "ERR_NICKNAMEINUSE.hpp"

ERR_NICKNAMEINUSE::ERR_NICKNAMEINUSE(void) {
	command = "433";
}

ERR_NICKNAMEINUSE::~ERR_NICKNAMEINUSE(void) {
}

ERR_NICKNAMEINUSE &ERR_NICKNAMEINUSE::operator = (ERR_NICKNAMEINUSE const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NICKNAMEINUSE::arranger(std::string const nicknameInUse, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + nicknameInUse + " :Nickname is already in use");
}
