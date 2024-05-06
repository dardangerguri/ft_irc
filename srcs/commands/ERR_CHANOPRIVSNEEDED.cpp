#include "ERR_CHANOPRIVSNEEDED.hpp"

ERR_CHANOPRIVSNEEDED::ERR_CHANOPRIVSNEEDED(void) {
	command = "482";
}

ERR_CHANOPRIVSNEEDED::~ERR_CHANOPRIVSNEEDED(void) {
}

ERR_CHANOPRIVSNEEDED &ERR_CHANOPRIVSNEEDED::operator = (ERR_CHANOPRIVSNEEDED const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_CHANOPRIVSNEEDED::arranger(Client *source, Channel *channel) {
	std::string	nickname;
	std::string	channelName;

	if (source)
		nickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + nickname + " " + channelName + " :You're not channel operator");
}
