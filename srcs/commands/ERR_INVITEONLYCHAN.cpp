#include "ERR_INVITEONLYCHAN.hpp"

ERR_INVITEONLYCHAN::ERR_INVITEONLYCHAN(void) {
	command = "473";
}

ERR_INVITEONLYCHAN::~ERR_INVITEONLYCHAN(void) {
}

ERR_INVITEONLYCHAN &ERR_INVITEONLYCHAN::operator = (ERR_INVITEONLYCHAN const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_INVITEONLYCHAN::arranger(Client *source, Channel *channel) {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :Cannot join channel (+i)");
}
