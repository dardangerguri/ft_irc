#include "USER.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

USER::USER(Commands *c) {
	commands = c;
	command = "USER";
	requireRegistration = false;
}

USER::~USER(void) {
}

USER &USER::operator = (USER const &copy) {
	(void)copy;
	return (*this);
}

void USER::handleCommand(std::string message, Client *source) {
	std::vector<std::string> parameters;
	if (!message.empty())
		parameters = parseMessage(message, source);

	if (parameters.size() == 4 && validateParameters(parameters)) {
		if (source->hasMode('r'))
			commands->sendCommand(commands->errAlreadyRegistered->arranger(source), source);
		else {
			if (source->getValidPass()) {
				source->setUsername(parameters[0]);
				source->setRealname(parameters[3]);
				if (source->tryToRegister())
					commands->registrationReply(source);
			}
			else
				commands->sendCommand(commands->errPasswMismatch->arranger(source), source);
		}
	}
	else
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command, source), source);
}

std::string USER::arranger() {
	return (this->command);
}

bool USER::validateParameters(std::vector<std::string> & parameters) {
	size_t maxUserLen = 12;

	if (parameters[0].size() > maxUserLen)
		parameters[0].resize(maxUserLen);

	if (parameters[3][0] == ':') {
		if (parameters[3].size() == 1) {
			return (false);
		}
		parameters[3].erase(0, 1);
	}
	return true;
}

std::vector<std::string> USER::parseMessage(std::string message, Client *source) {
	int	i = 0;

	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word, restOfMessage;

	while (i++ < 3 && ss >> word) {
		try {
			parameters.push_back(word);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
		}
	}


	std::getline(ss, restOfMessage);
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos) {
		try {
			parameters.push_back(restOfMessage.substr(restOfMessage.find_first_not_of(' ')));
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
		}
	}
	return (parameters);
}
