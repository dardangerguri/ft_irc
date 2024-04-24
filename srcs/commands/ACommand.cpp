#include "ACommand.hpp"

ACommand::ACommand(void) {
}

ACommand::~ACommand(void) {
}

std::vector<std::string> ACommand::parseMessage(std::string message) {
	//split them based on the spaces
	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;
	while (ss >> word) {
		parameters.push_back(word);
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
