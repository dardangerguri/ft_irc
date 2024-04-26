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

std::string ERR_NOSUCHCHANNEL::arranger(std::string channel, Client *source) {
	return (command + " " + source->getNickname() + " " + channel + " :No such channel");
}
