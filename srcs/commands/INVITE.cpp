#include "INVITE.hpp"

INVITE::INVITE(Commands *c) {
	commands = c;
	command = "INVITE";
}

INVITE::~INVITE(void) {
}

INVITE &INVITE::operator = (INVITE const &copy) {
	(void)copy;
	return (*this);
}

void INVITE::handleCommand(std::string const message, Client *source) {
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

	if (parameters.size() >= 2) {
		Channel *targetChannel = commands->server->getChannel(parameters[1]);
		if (targetChannel) {
			if (targetChannel->userIsJoined(source)) {
				if (targetChannel->hasMode('i') && !targetChannel->userIsOperator(source))
					commands->sendCommand(commands->errChanOPrivsNeeded->arranger(source, targetChannel), source);
				else {
					Client *targetClient = commands->server->getClient(parameters[0]);
					if (targetClient)
					{
						if (!targetChannel->userIsJoined(targetClient)) {
							targetClient->inviteToChannel(targetChannel);
							commands->sendCommand(commands->rplInviting->arranger(source, targetClient, targetChannel), source);
							commands->sendCommand(arranger(targetClient, targetChannel), source, targetClient);
						}
						else
							commands->sendCommand(commands->errUserOnChannel->arranger(source, targetClient, targetChannel), source);
					}
					else
						commands->sendCommand(commands->errNoSuchNick->arranger(parameters[0], source), source);
				}
			}
			else
				commands->sendCommand(commands->errNotOnChannel->arranger(source, targetChannel), source);
		}
		else
			commands->sendCommand(commands->errNoSuchChannel->arranger(parameters[1], source), source);
	}
	else
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
}

std::string const INVITE::arranger(Client *targetClient, Channel *targetChannel) const {
	std::string	targetNickname;
	std::string	targetChannelName;

	if (targetClient)
		targetNickname = targetClient->getNickname();
	if (targetChannel)
		targetChannelName = targetChannel->getName();

	return (this->command + " " + targetNickname + " " + targetChannelName);
}
