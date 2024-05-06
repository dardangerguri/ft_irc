#include "ERR_USERNOTINCHANNEL.hpp"

ERR_USERNOTINCHANNEL::ERR_USERNOTINCHANNEL(void) {
	command = "441";
}

ERR_USERNOTINCHANNEL::~ERR_USERNOTINCHANNEL(void) {
}

ERR_USERNOTINCHANNEL &ERR_USERNOTINCHANNEL::operator = (ERR_USERNOTINCHANNEL const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_USERNOTINCHANNEL::arranger(std::string nickname, Client *source, Channel *channel) {
	std::string	sourceNickname;
	std::string	channelName;

	if (source)
		sourceNickname = source->getNickname();
	if (channel)
		channelName = channel->getName();

	return (command + " " + sourceNickname + " " + nickname + " " + channelName + " :They aren't on that channel");
}