#include "RPL_CHANNELMODEIS.hpp"

RPL_CHANNELMODEIS::RPL_CHANNELMODEIS(void) {
	command = "324";
}

RPL_CHANNELMODEIS::~RPL_CHANNELMODEIS(void) {
}

RPL_CHANNELMODEIS &RPL_CHANNELMODEIS::operator = (RPL_CHANNELMODEIS const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_CHANNELMODEIS::arranger(Client *source, Channel *channel) const {
	const std::unordered_set<char>	supportedModes = {'i', 't', 'l', 'k'};
	std::string						channelName;
	std::string						nickname;
	std::string						message;
	std::vector<std::string>		modes;

	if (source)
		nickname = source->getNickname();

	if (channel) {
		channelName = channel->getName();
		try {
			modes.push_back("+");
			for (char mode : supportedModes) {
				if (channel->hasMode(mode)) {
					modes[0] += mode;
					if (mode == 'l')
						modes.push_back(std::to_string(channel->getUserLimit()));
					if (mode == 'k') {
						if (channel->userIsJoined(source))
							modes.push_back(channel->getPassword());
						else
							modes.push_back("Sensitive");
					}
				}
			}
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding parameters to the list has failed", source), source);
			return "";
		}
	}

	for (size_t i = 0; i < modes.size(); i++) {
		message += modes[i];
		if (i + 1 < modes.size())
			message += " ";
	}

	return (command + " " + nickname + " " + channelName + " " + message);
}
