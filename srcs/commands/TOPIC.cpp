#include "TOPIC.hpp"

TOPIC::TOPIC(Commands *c) {
	commands = c;
	command = "TOPIC";
}

TOPIC::~TOPIC(void) {
}

TOPIC &TOPIC::operator = (TOPIC const &copy) {
	(void)copy;
	return (*this);
}

void TOPIC::handleCommand(std::string message, Client *source) {
	std::vector<std::string>	parameters;
	Channel						*channel;

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
	else if (parameters[0][0] == '#') {
		channel = commands->server->getChannel(parameters[0]);
		if (channel) {
			if (parameters.size() == 1) {
				if (channel->userIsJoined(source)) {
					if (channel->getTopic().empty())
						commands->sendCommand(commands->rplNoTopic->arranger(source, channel), source);
					else {
						commands->sendCommand(commands->rplTopic->arranger(source, channel), source);
						commands->sendCommand(commands->rplTopicWhoTime->arranger(source, channel), source);
					}
				}
				else
					commands->sendCommand(commands->errNotOnChannel->arranger(source, channel), source);
			}
			else {
				if (channel->hasMode('t')) {
					if (!channel->userIsOperator(source)) {
						commands->sendCommand(commands->errChanOPrivsNeeded->arranger(source, channel), source);
						return ;
					}
				}
				if (parameters[1][0] == ':' && parameters[1].size() == 1) {
					channel->setTopic("");
					channel->setTopicTime(getCurrTime());
					channel->setTopicAuthor(source);
					commands->sendCommand(arranger(channel, ""), source, channel);
				}
				else if (parameters[1][0] == ':') {
					parameters[1].erase(0, 1);
					channel->setTopic(parameters[1]);
					channel->setTopicTime(getCurrTime());
					channel->setTopicAuthor(source);
					commands->sendCommand(arranger(channel, parameters[1]), source, channel);
				}
			}
		}
		else
			commands->sendCommand(commands->errNoSuchChannel->arranger(parameters[0], source), source);
	}
}

std::string TOPIC::arranger(Channel *channel, std::string topic) {
	std::string	channelName;

	if (channel)
		channelName = channel->getName();

	return (command + " " + channelName + " :" + topic);
}

std::time_t	TOPIC::getCurrTime(void) {
	std::chrono::system_clock::time_point n = std::chrono::system_clock::now();
	std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(n.time_since_epoch());
	std::time_t unix_timestamp = s.count();
	return (unix_timestamp);
}

std::vector<std::string> TOPIC::parseMessage(std::string message) {

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
