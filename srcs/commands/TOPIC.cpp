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
		parameters[0].erase(0, 1);
		channel = commands->server->getChannel(parameters[0]);
		if (channel) {
			if (parameters.size() == 1) {
				// check topic: send (RPL_TOPIC & RPL_TOPICWHOTIME) or RPL_NOTOPIC or ERR_NOTONCHANNEL
				if (channel->userIsJoined(source)) {
					if (channel->getTopic().empty())
						return ; // RPL_NOTOPIC (331) 
					else
						return ; // RPL_TOPIC (332) & RPL_TOPICWHOTIME (333)
				}
				else
					return ; // ERR_NOTONCHANNEL (442)
			}
			else {
				// set topic (still need to check for modes and stuff, this is still rough prototype)
				if (channel->hasMode('t')) {
					if (!source->hasMode('o') && !source->hasMode('O') && !channel->userIsOperator(source)) {
						return ; //ERR_CHANOPRIVSNEEDED (482)
					}
				}
				if (parameters[1][0] == ':' && parameters[1].size() == 1) {
					channel->setTopic("");
					commands->sendCommand(commands->topic->arranger(command, channel, parameters), source, channel);
				}
				else if (parameters[1][0] == ':') {
					placeholder = parameters[1];
					placeholder.erase(0, 1);
					channel->setTopic(placeholder);
					commands->sendCommand(commands->topic->arranger(command, channel, parameters), source, channel);
				}
				// we could just sendCommand here, but I'm not sure how to deal with if there is no ":" at the beginning of the topic name
				// now we don't do anything if its missing
			}
		}
		else
			return ; // ERR_NOSUCHCHANNEL (403)
	}
}

std::string TOPIC::arranger(std::string command, Channel *channel, std::string parameters) {
	return (command + " " + "#" + channel->getName() + " " + parameters); //paramaters is going to have the ":" at the beginning
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