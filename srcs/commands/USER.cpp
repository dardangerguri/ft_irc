#include "USER.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

USER::USER(Commands *c) {
	commands = c;
	command = "USER";
}

USER::~USER(void) {
}

USER &USER::operator = (USER const &copy) {
	(void)copy;
	return (*this);
}

void USER::handleCommand(std::string message, Client *source) {
	std::vector<std::string> parameters = parseMessage(message);
	if (parameters.size() == 4 && validateParameters(parameters)) {
		if (source->hasMode('r'))
			return; //FIXME send back ERR_ALREADYREGISTERED
		else {
			source->setUsername(parameters[0]);
			source->setRealname(parameters[3]);
			source->tryToRegister();
		}
	}
	else
		commands->sendCommand(commands->errNeedMoreParams->arranger(this->command), source);
}

std::string USER::arranger() {
	return (this->command);
}

bool USER::validateParameters(std::vector<std::string> & parameters) {
	size_t maxUserLen = 12;

	if (parameters[1] != "0" || parameters[2] != "*")
		return (false);

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

std::vector<std::string> USER::parseMessage(std::string message) {
	int	i = 0;

	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word, restOfMessage;

	while (i++ < 3 && ss >> word)
		parameters.push_back(word);

	std::getline(ss, restOfMessage);
	size_t pos = restOfMessage.find_first_not_of(' ');
	if (pos != std::string::npos)
		parameters.push_back(restOfMessage.substr(restOfMessage.find_first_not_of(' ')));

	return (parameters);
}
