#include "ERR_NONICKNAMEGIVEN.hpp"

ERR_NONICKNAMEGIVEN::ERR_NONICKNAMEGIVEN(void) {
	command = "431";
}

ERR_NONICKNAMEGIVEN::~ERR_NONICKNAMEGIVEN(void) {
}

ERR_NONICKNAMEGIVEN &ERR_NONICKNAMEGIVEN::operator = (ERR_NONICKNAMEGIVEN const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NONICKNAMEGIVEN::arranger(Client *source) {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :No nickname given");
}
