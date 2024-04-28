#include "ERR_NOSUCHNICK.hpp"

ERR_NOSUCHNICK::ERR_NOSUCHNICK(void) {
	command = "401";
}

ERR_NOSUCHNICK::~ERR_NOSUCHNICK(void) {
}

ERR_NOSUCHNICK &ERR_NOSUCHNICK::operator = (ERR_NOSUCHNICK const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOSUCHNICK::arranger(std::string sourceNickname, Client *source) {
	return (command + " " + source->getNickname() + " " + sourceNickname + " :No such nick/channel");
}
