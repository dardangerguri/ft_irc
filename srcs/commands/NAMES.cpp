#include "NAMES.hpp"

NAMES::NAMES(Commands *c) {
	commands = c;
	command = "NAMES";
}

NAMES::~NAMES(void) {
}

NAMES &NAMES::operator = (NAMES const &copy) {
	(void)copy;
	return (*this);
}

void NAMES::handleCommand(std::string const message, Client *source) {
	std::vector<std::string> parameters;
	if (!message.empty()) {
		try {
			parameters = parseMessage(message);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding parameters to the list has failed", source), source);
			return ;
		}
	}

	if (parameters.empty())
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
	else {
		std::vector<std::string>	channels;
		Channel						*channel;

		try {
			channels = splitComma(parameters[0]);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
			return ;
		}

		for (std::string channelName : channels) {
			channel = commands->server->getChannel(channelName);

			if (channel)
				commands->namesReply(source, channel);
			else
				commands->sendCommand(commands->rplEndOfNames->arranger(source, channelName), source);
		}
	}
}

std::string const NAMES::arranger(Channel *targetChannel) const {
	return (this->command + " " + targetChannel->getName());
}
