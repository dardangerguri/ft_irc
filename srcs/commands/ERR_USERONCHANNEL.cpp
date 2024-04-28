#include "ERR_USERONCHANNEL.hpp"

ERR_USERONCHANNEL::ERR_USERONCHANNEL(void) {
	command = "443";
}

ERR_USERONCHANNEL::~ERR_USERONCHANNEL(void) {
}

ERR_USERONCHANNEL &ERR_USERONCHANNEL::operator = (ERR_USERONCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_USERONCHANNEL::arranger(Client *source, Client *target, Channel *channel) {
	return (command + " " + source->getNickname() + " " + target->getNickname() + " " + channel->getName() + \
	" :is already on channel");
}
