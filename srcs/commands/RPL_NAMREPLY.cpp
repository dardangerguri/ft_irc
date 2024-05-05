#include "RPL_NAMREPLY.hpp"

RPL_NAMREPLY::RPL_NAMREPLY(void) {
	command = "353";
}

RPL_NAMREPLY::~RPL_NAMREPLY(void) {
}

RPL_NAMREPLY &RPL_NAMREPLY::operator = (RPL_NAMREPLY const &copy) {
	(void)copy;
	return (*this);
}

// Only send one user at the time, so we don't have to worry about message getting too long
std::string RPL_NAMREPLY::arranger(Client *source, Channel *channel, Client *user) {
	std::string userPrefix;

	if (channel->userIsOperator(user))
		userPrefix = "@";

	return (command + " " + source->getNickname() + " = " + channel->getName() + " :" \
	+ userPrefix + user->getNickname());
}
