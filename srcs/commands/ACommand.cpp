#include "ACommand.hpp"

ACommand::ACommand(void) {
}

ACommand::~ACommand(void) {
}

std::vector<std::string> ACommand::parseMessage(std::string message, Client *source) {
	//split them based on the spaces
	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;
	while (ss >> word) {
		try {
			parameters.push_back(word);
		}
		catch (...) {
			commands->sendCommand(commands->errUnknownError->arranger \
			(this->command, "Adding the parameter to the list has failed", source), source);
		}
	}
	return (parameters);
}

void ACommand::handleCommand(std::string message, Client *source) {
	(void)message;
	(void)source;
}

bool ACommand::getRequireRegistration(void) {
	return (requireRegistration);
}

// NOTE: The function can fail with an exception
std::vector<std::string> ACommand::splitComma(std::string input) const {
	std::vector<std::string>	parameters;
	std::stringstream			ss(input);
	std::string					param;

	while(ss.good())
	{
		getline(ss, param, ',');
		parameters.push_back(param);
	}

	return (parameters);
}
