#include "ERR_NOOPERHOST.hpp"

ERR_NOOPERHOST::ERR_NOOPERHOST(void) {
	command = "491";
}

ERR_NOOPERHOST::~ERR_NOOPERHOST(void) {
}

ERR_NOOPERHOST &ERR_NOOPERHOST::operator = (ERR_NOOPERHOST const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOOPERHOST::arranger(Client *source) {
	std::string nickname;

	if (source)
		nickname = source->getNickname();
	return (command + " " + nickname + " :No O-lines for your host");
}
