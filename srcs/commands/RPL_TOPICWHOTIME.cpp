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

std::string const RPL_TOPICWHOTIME::arranger(Client *source, Channel *channel) const {
	std::string	nickname;
	std::string	channelName;
	std::string	topicAuthor;
	std::string	topicTime;

	if (source)
		nickname = source->getNickname();
	if (channel) {
		channelName = channel->getName();
		topicAuthor = channel->getTopicAuthor();
		try {
			topicTime = std::to_string(channel->getTopicTime());
		}
		catch (...) {
			topicTime = "0";
		}
	}

	return (command + " " + nickname + " " + channelName + " " + topicAuthor + " " + topicTime);
}
