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

std::string ERR_NOSUCHCHANNEL::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + channel->getChannelName() + " :No such channel");
}
