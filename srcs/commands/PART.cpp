#include "PART.hpp"

PART::PART(Commands *c) {
	commands = c;
	command = "PART";
}

PART::~PART(void) {
}

PART &PART::operator = (PART const &copy) {
	(void)copy;
	return (*this);
}

void PART::handleCommand(std::string message, Client *source) {
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
		std::string					reason;
		Channel						*channel;

		if (parameters.size() >= 2)
			reason = parameters[1].erase(0, 1);

		try {
			channels = splitComma(parameters[0]);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
		}

		for (std::string channelName : channels) {
			channel = commands->server->getChannel(channelName);

			if (!channel)
				commands->sendCommand(commands->errNoSuchChannel->arranger(channelName, source), source);
			else if (!channel->userIsJoined(source))
				commands->sendCommand(commands->errNotOnChannel->arranger(source, channel), source);
			else {
				commands->sendCommand(arranger(channel, reason), source, channel);
				channel->userLeave(source);
				if (channel->getUserCount() == 0)
					commands->server->delChannel(channel);
			}
		}
	}
}

std::string PART::arranger(Channel *channel, std::string reason) {
	std::string	channelName;

	if (channel)
		channelName = channel->getName();

	if (reason.empty())
		return (command + " " + channelName);
	else
		return (command + " " + channelName + " :" + reason);
}

std::vector<std::string> PART::parseMessage(std::string message) {
	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;
	std::string					restOfMessage;

	ss >> word;
	parameters.push_back(word);

	std::getline(ss, restOfMessage);
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos) {
			parameters.push_back(restOfMessage.substr(pos));
	}
	return (parameters);
}
