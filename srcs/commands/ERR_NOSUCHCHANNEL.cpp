#include "ERR_NOSUCHCHANNEL.hpp"

ERR_NOSUCHCHANNEL::ERR_NOSUCHCHANNEL(void) {
	command = "403";
}

ERR_NOSUCHCHANNEL::~ERR_NOSUCHCHANNEL(void) {
}

ERR_NOSUCHCHANNEL &ERR_NOSUCHCHANNEL::operator = (ERR_NOSUCHCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_NOSUCHCHANNEL::arranger(std::string const channel, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + channel + " :No such channel");
}
