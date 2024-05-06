#include "PRIVMSG.hpp"

PRIVMSG::PRIVMSG(Commands *c) {
	commands = c;
	command = "PRIVMSG";
}

PRIVMSG::~PRIVMSG(void) {
}

PRIVMSG &PRIVMSG::operator = (PRIVMSG const &copy) {
	(void)copy;
	return (*this);
}

void PRIVMSG::handleCommand(std::string message, Client *source) {
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

	if (parameters.size() == 2) {
		if (parameters[0][0] == '#') {
			Channel *targetChannel = commands->server->getChannel(parameters[0]);
			if (targetChannel) {
				if (parameters[1][0] != ':')
					commands->sendCommand(commands->errNoTextToSend->arranger(source), source);
				else
					commands->sendCommand(arranger(targetChannel, parameters[1]), source, targetChannel, source);
			}
			else
				commands->sendCommand(commands->errNoSuchNick->arranger(parameters[0], source), source);
		}
		else {
			Client *targetClient = commands->server->getClient(parameters[0]);
			if (targetClient) {
				if (parameters[1][0] != ':')
					commands->sendCommand(commands->errNoTextToSend->arranger(source), source);
				else
					commands->sendCommand(arranger(targetClient, parameters[1]), source, targetClient);
			}
			else
				commands->sendCommand(commands->errNoSuchNick->arranger(parameters[0], source), source);
		}
	}
	else if (parameters.empty() || parameters[0][0] == ':')
		commands->sendCommand(commands->errNoRecipient->arranger(this->command, source), source);
	else
		commands->sendCommand(commands->errNoTextToSend->arranger(source), source);
}

std::string PRIVMSG::arranger(Client *target, std::string message) {
	std::string	targetNickname;

	if (target)
		targetNickname = target->getNickname();

	return (this->command + " " + targetNickname + " " + message);
}

std::string PRIVMSG::arranger(Channel *target, std::string message) {
	std::string	targetChannelName;

	if (target)
		targetChannelName = target->getName();

	return (this->command + " " + targetChannelName + " " + message);
}

std::vector<std::string> PRIVMSG::parseMessage(std::string message) {

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
