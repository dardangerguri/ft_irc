#include "MODE.hpp"

MODE::MODE(Commands *c) {
	commands = c;
	command = "MODE";
}

MODE::~MODE(void) {
}

MODE &MODE::operator = (MODE const &copy) {
	(void)copy;
	return (*this);
}

void MODE::handleCommand(std::string message, Client *source) {
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

	else if (parameters[0][0] == '#') {
		Channel *targetChannel = commands->server->getChannel(parameters[0]);
		if (!targetChannel)
			commands->sendCommand(commands->errNoSuchChannel->arranger(parameters[0], source), source);
		else if (parameters.size() == 1)
			commands->sendCommand(commands->rplChannelModeIs->arranger(source, targetChannel), source);
		else if (!targetChannel->userIsOperator(source))
			commands->sendCommand(commands->errChanOPrivsNeeded->arranger(source, targetChannel), source);
		else
			handleChannelModes(parameters, source, targetChannel);
	}

	else {
		Client *targetClient = commands->server->getClient(parameters[0]);
		if (!targetClient)
			commands->sendCommand(commands->errNoSuchNick->arranger(parameters[0], source), source);
		else if (source->getNickname() != targetClient->getNickname())
			commands->sendCommand(commands->errUsersDontMatch->arranger(source), source);
		else if (parameters.size() == 1)
			commands->sendCommand(commands->rplUModeIs->arranger(targetClient), source);
		else
			handleClientModes(parameters, source, targetClient);
	}
}

void MODE::handleClientModes(std::vector<std::string> parameters, Client *source, Client *targetClient) {
	size_t	i = 0;
	bool	unknownModeFlag = false;
	bool	modeFlag = false;

	while (parameters[1][i]) {
		if (parameters[1][i] == 'o' && !modeFlag) {
			if (parameters[1][i - 1] && parameters[1][i] == '-') {
				if (targetClient->hasMode('o')) {
					targetClient->delMode('o');
					commands->sendCommand(arranger("-o", targetClient), source, source);
				}
			}
			modeFlag = true;
		}
		else if (parameters[1][i] != 'o' && parameters[1][i] != '+' && parameters[1][i] != '-')
			unknownModeFlag = true;
		i++;
	}
	if (unknownModeFlag)
		commands->sendCommand(commands->errUModeUnknownFlag->arranger(source), source);
}

void MODE::handleChannelModes(std::vector<std::string> parameters, Client *source, Channel *targetChannel) {
	size_t						i = 0;
	size_t						parameter = 2;
	bool						setFlag = true;
	bool						keyFlag = false;
	bool						clientLimitFlag = false;
	bool						inviteOnlyFlag = false;
	bool						protectedTopicFlag = false;
	std::string					modeString;
	std::vector<std::string>	modeParameters;

	while (parameters[1][i]) {

		if ((parameters[1][i] == '+' || parameters[1][i] == '-') && parameters[1][i + 1] \
			&& (parameters[1][i + 1] == 'o' || parameters[1][i + 1] == 'k' || parameters[1][i + 1] == 'l' \
			|| parameters[1][i + 1] == 'i' || parameters[1][i + 1] == 't')) {

			if (parameters[1][i] == '+' && !setFlag) {
				setFlag = true;
				modeString += '+';
			}

			else if (parameters[1][i] == '-' && setFlag) {
				setFlag = false;
				modeString += '-';
			}
		}

		else if (parameters[1][i] == 'o') {
			if (parameter < parameters.size()) {
				if (handleChannelOperatorMode(parameters[parameter], setFlag, source, targetChannel)) {
					try {
						modeString += 'o';
						modeParameters.push_back(parameters[parameter]);
					}
					catch (...) {
						commands->sendCommand(commands->errUnknownError->arranger \
						(this->command, "Adding parameters to the list has failed", source), source);
					}
				}
				parameter++;
			}
		}

		else if (parameters[1][i] == 'k') {
			if (parameter < parameters.size()) {
				if (handleKeyMode(parameters[parameter], setFlag, keyFlag, targetChannel)) {
					try {
						modeString += 'k';
						modeParameters.push_back(parameters[parameter]);
					}
					catch (...) {
						commands->sendCommand(commands->errUnknownError->arranger \
						(this->command, "Adding parameters to the list has failed", source), source);
					}
				}
				parameter++;
			}
			keyFlag = true;
		}

		else if (parameters[1][i] == 'l') {
			if (parameter < parameters.size() && setFlag) {
				if (handleClientLimitMode(parameters[parameter], setFlag, clientLimitFlag, targetChannel)) {
					try {
						modeString += 'l';
						modeParameters.push_back(std::to_string(targetChannel->getUserLimit()));
					}
					catch (...) {
						commands->sendCommand(commands->errUnknownError->arranger \
						(this->command, "Adding parameters to the list has failed", source), source);
					}
				}
				parameter++;
			}
			else if (setFlag) {
				commands->sendCommand(commands->errNeedMoreParams->arranger("MODE +l", source), source);
			}
			else if (!setFlag) {
				if (handleClientLimitMode("", setFlag, clientLimitFlag, targetChannel))
					modeString += parameters[1][i];
			}
			clientLimitFlag = true;
		}

		else if (parameters[1][i] == 'i') {
			if (!inviteOnlyFlag) {
				handleInviteOnlyMode(setFlag, targetChannel);
				modeString += 'i';
			}
			inviteOnlyFlag = true;
		}

		else if (parameters[1][i] == 't') {
			if (!protectedTopicFlag) {
				handleTopicMode(setFlag, targetChannel);
				modeString += 't';
			}
			protectedTopicFlag = true;
		}

		else if (parameters[1][i] != '+' && parameters[1][i] != '-')
			commands->sendCommand(commands->errUnknownMode->arranger(parameters[1][i], source), source);

		i++;
	}
	std::string message = parseModeMessage(modeString, modeParameters);
	if (!message.empty())
		commands->sendCommand(arranger(message, targetChannel), source, targetChannel);
}

bool MODE::handleChannelOperatorMode(std::string parameter, bool setFlag, Client *source, Channel *targetChannel) {
	Client *targetClient = commands->server->getClient(parameter);
	if (!targetClient || !targetChannel->userIsJoined(targetClient)) {
		if (!targetClient)
			commands->sendCommand(commands->errNoSuchNick->arranger(parameter, source), source);
		commands->sendCommand(commands->errUserNotInChannel->arranger(parameter, source, targetChannel), source);
		return (false);
	}
	else {
		if (setFlag)
			targetChannel->userMakeOperator(targetClient);
		else if (!setFlag)
			targetChannel->userRemoveOperator(targetClient);
		return (true);
	}
}

bool MODE::handleKeyMode(std::string parameter, bool setFlag, bool &keyFlag, Channel *targetChannel) {
	if (setFlag) {
		if (!keyFlag) {
			targetChannel->setPassword(parameter);
			targetChannel->addMode('k');
			return (true);
		}
		else
			return (false);
	}
	else {
		if (!keyFlag && targetChannel->hasMode('k') && targetChannel->checkPassword(parameter))
			targetChannel->delMode('k');
		else
			return (false);
	}
	return (true);
}

bool MODE::handleClientLimitMode(std::string parameter, bool setFlag, bool &clientLimitFlag, Channel *targetChannel) {
	if (setFlag) {
		int	userLimit;
		try {
			userLimit = stoi(parameter);
			if (!clientLimitFlag) {
				targetChannel->setUserLimit(userLimit);
				targetChannel->addMode('l');
			}
		}
		catch (...) {
			return (false);
		}
	}
	else {
		if (!clientLimitFlag)
			targetChannel->delMode('l');
		else
			return (false);
	}
	return (true);
}

void MODE::handleInviteOnlyMode(bool setFlag, Channel *targetChannel) {
	if (setFlag)
		targetChannel->addMode('i');
	else
		targetChannel->delMode('i');
}

void MODE::handleTopicMode(bool setFlag, Channel *targetChannel) {
	if (setFlag)
		targetChannel->addMode('t');
	else
		targetChannel->delMode('t');
}

std::string MODE::parseModeMessage(std::string modeString, std::vector<std::string> modeParameters) {
	if (modeString[0] && modeString[0] != '+' && modeString[0] != '-')
		modeString = "+" + modeString;

	std::unordered_set<std::string> sets = {"+-", "-+", "--", "++"};
	for (std::string set : sets) {
		size_t	pos = 0;
		while ((pos = modeString.find(set, pos)) != std::string::npos) {
			if (modeString[pos + 2] == '+' || modeString[pos + 2] == '-')
				modeString.erase(pos, 2);
			else
				modeString.erase(modeString.begin() + pos);
		}
	}

	if (modeString.empty() || modeString.size() == 1)
		return ("");

	for (size_t i = 0; i < modeParameters.size(); i++) {
		if (i == 0)
			modeString += " ";
		modeString += modeParameters[i];
		if (i + 1 < modeParameters.size())
			modeString += " ";
	}
	return (modeString);
}

std::string MODE::arranger(std::string message, Channel *targetChannel) {
	std::string	targetChannelName;

	if (targetChannel)
		targetChannelName = targetChannel->getName();

	return (command + " " + targetChannelName + " " + message);
}

std::string MODE::arranger(std::string message, Client *targetClient) {
	std::string	targetClientNickname;

	if (targetClient)
		targetClientNickname = targetClient->getNickname();

	return (command + " " + targetClientNickname + " " + message);
}
