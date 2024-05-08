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

std::string const RPL_TOPIC::arranger(Client *source, Channel *channel) const {
	std::string	nickname;
	std::string	channelName;
	std::string	topic;

	if (source)
		nickname = source->getNickname();
	if (channel) {
		channelName = channel->getName();
		topic = channel->getTopic();
	}
	return (command + " " + nickname + " " + channelName + " :" + topic);
}
