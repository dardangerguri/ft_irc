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
	std::string					placeholder;

	if (!message.empty())
		parameters = parseMessage(message, source);
	if (parameters.empty())
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
	else if (parameters[0][0] == '#') {
		channel = commands->server->getChannel(parameters[0]);
		if (channel) {
			if (parameters.size() == 1) {
				if (channel->userIsJoined(source)) {
					if (channel->getTopic().empty())
						commands->sendCommand(commands->rplNoTopic->arranger(source, channel), channel);
					else {
						commands->sendCommand(commands->rplTopic->arranger(source, channel), channel);
						commands->sendCommand(commands->rplTopicWhoTime->arranger(source, channel), channel);
					}
				}
				else
					commands->sendCommand(commands->errNotOnChannel->arranger(source, channel), channel);
			}
			else {
				if (channel->hasMode('t')) {
					if (!channel->userIsOperator(source)) {
						commands->sendCommand(commands->errChanOPrivsNeeded->arranger(source, channel), channel);
						return ;
					}
				}
				if (parameters[1][0] == ':' && parameters[1].size() == 1) {
					channel->setTopic("");
					channel->setTopicTime(getCurrTime());
					channel->setTopicAuthor(source);
					commands->sendCommand(arranger(command, channel, parameters[1]), source, channel);
				}
				else if (parameters[1][0] == ':') {
					placeholder = parameters[1];
					placeholder.erase(0, 1);
					channel->setTopic(placeholder);
					channel->setTopicTime(getCurrTime());
					channel->setTopicAuthor(source);
					commands->sendCommand(arranger(command, channel, parameters[1]), source, channel);
				}
			}
		}
		else
			commands->sendCommand(commands->errNoSuchChannel->arranger(parameters[0], source), channel);
	}
}

std::string TOPIC::arranger(std::string command, Channel *channel, std::string parameters) {
	return (command + " " + channel->getName() + " " + parameters);
}

std::time_t	TOPIC::getCurrTime(void) {
	std::chrono::system_clock::time_point n = std::chrono::system_clock::now();
	std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>(n.time_since_epoch());
	std::time_t unix_timestamp = s.count();
	return (unix_timestamp);
}

std::vector<std::string> TOPIC::parseMessage(std::string message, Client *source) {

	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;
	std::string					restOfMessage;

	ss >> word;
	try {
		parameters.push_back(word);
	}
	catch (...) {
		commands->sendCommand(commands->errUnknownError->arranger \
		(this->command, "Adding the parameter to the list has failed", source), source);
	}

	std::getline(ss, restOfMessage);
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos) {
		try {
			parameters.push_back(restOfMessage.substr(pos));
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
		}
	}
	return (parameters);
}