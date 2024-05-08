#include "ERR_UMODEUNKNOWNFLAG.hpp"

ERR_UMODEUNKNOWNFLAG::ERR_UMODEUNKNOWNFLAG(void) {
	command = "501";
}

ERR_UMODEUNKNOWNFLAG::~ERR_UMODEUNKNOWNFLAG(void) {
}

ERR_UMODEUNKNOWNFLAG &ERR_UMODEUNKNOWNFLAG::operator = (ERR_UMODEUNKNOWNFLAG const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_UMODEUNKNOWNFLAG::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :Unknown MODE flag");
}
