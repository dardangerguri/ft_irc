#include "KICK.hpp"

KICK::KICK(Commands *c) {
	commands = c;
	command = "KICK";
}

KICK::~KICK(void) {
}

KICK &KICK::operator = (KICK const &copy) {
	(void)copy;
	return (*this);
}

void KICK::handleCommand(std::string const message, Client *source) {
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

	if (parameters.size() < 2)
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
	else {
		Channel	*channel;

		channel = commands->server->getChannel(parameters[0]);
		if (!channel)
			commands->sendCommand(commands->errNoSuchChannel->arranger(parameters[0], source), source);
		else if (!channel->userIsJoined(source))
			commands->sendCommand(commands->errNotOnChannel->arranger(source, channel), source);
		else if (!channel->userIsOperator(source))
			commands->sendCommand(commands->errChanOPrivsNeeded->arranger(source, channel), source);
		else {
			std::string						kickReason = "gtfo";
			std::vector<std::string>		removeUsers;
			std::unordered_set<Client *>	channelUsers;

			try {
				removeUsers = splitComma(parameters[1]);
			}
			catch (...) {
				commands->sendCommand(commands->errUnknownError->arranger \
				(this->command, "Adding the parameter to the list has failed", source), source);
				return ;
			}

			channelUsers = channel->getUserList();
			if (parameters.size() > 2)
				kickReason = parameters[2];
			for (const std::string& user : removeUsers) {
				Client *client = commands->server->getClient(user);
				if (channel->userIsJoined(client)) {
					commands->sendCommand(arranger(channel, client, kickReason), source, channel);
					channel->userLeave(client);
					if (channel->getUserCount() == 0)
						commands->server->delChannel(channel);
				}
				else {
					commands->sendCommand(commands->errUserNotInChannel->arranger(user, source, channel), source);
				}
			}
		}
	}
}

std::string const KICK::arranger(Channel *channel, Client *removedUser, std::string const reason) const {
	std::string channelName;
	std::string removedUserName;

	if (channel)
		channelName = channel->getName();
	if (removedUser)
		removedUserName = removedUser->getNickname();

	return (this->command + " " + channelName + " " + removedUserName + " " + reason);
}

std::vector<std::string> KICK::parseMessage(std::string const message) const {
	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;
	std::string					restOfMessage;

	while (ss >> word) {
		if (word[0] == ':' && word.size() == 1)
			break ;
		if (word[0] == ':')
		{
			std::getline(ss, restOfMessage);
			parameters.push_back(word + restOfMessage);
			break ;
		}
		else
			parameters.push_back(word);
	}

	return (parameters);
}
