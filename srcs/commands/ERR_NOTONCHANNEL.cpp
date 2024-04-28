#include "ERR_NOTONCHANNEL.hpp"

ERR_NOTONCHANNEL::ERR_NOTONCHANNEL(void) {
	command = "442";
}

ERR_NOTONCHANNEL::~ERR_NOTONCHANNEL(void) {
}

ERR_NOTONCHANNEL &ERR_NOTONCHANNEL::operator = (ERR_NOTONCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOTONCHANNEL::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() + " :You're not on that channel");
}
