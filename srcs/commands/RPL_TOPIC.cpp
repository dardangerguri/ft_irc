#include "RPL_TOPIC.hpp"

RPL_TOPIC::RPL_TOPIC(void) {
	command = "332";
}

RPL_TOPIC::~RPL_TOPIC(void) {
}

RPL_TOPIC &RPL_TOPIC::operator = (RPL_TOPIC const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_TOPIC::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() + " :" \
	+ channel->getTopic());
}
