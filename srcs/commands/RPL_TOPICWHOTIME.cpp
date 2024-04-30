#include "RPL_TOPICWHOTIME.hpp"

RPL_TOPICWHOTIME::RPL_TOPICWHOTIME(void) {
	command = "333";
}

RPL_TOPICWHOTIME::~RPL_TOPICWHOTIME(void) {
}

RPL_TOPICWHOTIME &RPL_TOPICWHOTIME::operator = (RPL_TOPICWHOTIME const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_TOPICWHOTIME::arranger(Client *source, Channel *channel) {
	return (command + " " + source->getNickname() + " " + channel->getName() \
	+ " " + channel->getTopicAuthor() + " " + std::to_string(channel->getTopicTime()));
}
