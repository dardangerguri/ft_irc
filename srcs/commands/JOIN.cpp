#include "JOIN.hpp"

JOIN::JOIN(Commands *c) {
	commands = c;
	command = "JOIN";
}

JOIN::~JOIN(void) {
}

JOIN &JOIN::operator = (JOIN const &copy) {
	(void)copy;
	return (*this);
}

void JOIN::handleCommand(std::string message, Client *source) {
	std::vector<std::string>	parameters;

	if (!message.empty())
		parameters = parseMessage(message, source);

	if (parameters.empty())
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
	else if (parameters[0] == "0") {
		// PART every joined channel
		for (std::pair<std::string, Channel *> chanPair : source->getJoinedChannels()) {
			commands->part->handleCommand(chanPair.second->getName(), source);
		}
	}
	else {
		std::vector<std::string>	channels;
		std::vector<std::string>	channelKeys;
		unsigned int				channelsCount;
		unsigned int				channelKeysCount;
		Channel						*channel;

		try {
			channels = splitComma(parameters[0]);
			if (parameters.size() >= 2)
				channelKeys = splitComma(parameters[1]);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
			return ;
		}

		channelsCount = channels.size();
		channelKeysCount = channelKeys.size();

		for (unsigned int i = 0; i < channelsCount; i++) {
			if (channels[i][0] != '#') {
				commands->sendCommand(commands->errBadChanMask->arranger(channels[i]), source);
				continue ;
			}

			channel = commands->server->getChannel(channels[i]);
			if (!channel) {
				channel = commands->server->addChannel(channels[i]);
				if (!channel) {
					commands->sendCommand(commands->errUnknownError->arranger \
					(this->command, "Failed to create a new channel: " + channels[i], source), source);
					continue ;
				}
			}

			if (channel->hasMode('i') && !source->isInvitedToChannel(channel)) {
				commands->sendCommand(commands->errInviteOnlyChan->arranger(source, channel), source);
				continue ;
			}

			if (channel->hasMode('k')) {
				if (i >= channelKeysCount) {
					commands->sendCommand(commands->errBadChannelKey->arranger(source, channel), source);
					continue ;
				}
				else if (!channel->validatePassword(channelKeys[i])) {
					commands->sendCommand(commands->errInvalidKey->arranger(source, channel), source);
					continue ;
				}
			}

			if (channel->hasMode('l') && channel->getUserCount() >= channel->getUserLimit()) {
				commands->sendCommand(commands->errChannelIsFull->arranger(source, channel), source);
				continue ;
			}

			channel->userJoin(source);
			commands->sendCommand(arranger(channel), source, channel);
			if (!channel->getTopic().empty()) {
				commands->sendCommand(commands->rplTopic->arranger(source, channel), source);
				commands->sendCommand(commands->rplTopicWhoTime->arranger(source, channel), source);
			}
			commands->namesReply(source, channel);
		}
	}
}

std::string JOIN::arranger(Channel *channel) {
	return (command + " " + channel->getName());
}
