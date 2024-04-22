#include "NICK.hpp"

NICK::NICK(Commands *c) {
	commands = c;
	command = "NICK";
}

NICK::~NICK(void) {
}

NICK &NICK::operator = (NICK const &copy) {
	(void)copy;
	return (*this);
}

void NICK::handleCommand(std::string message, Client *source) {
	std::vector<std::string> parameters = parseMessage(message);
	if (parameters.empty())
		return; //FIXME send ERR_NONICKNAMEGIVEN
	else if (validateNickname(parameters[0])) {
		if (commands->server->nickExists(parameters[0]))
			return; //FIXME send ERR_NICKNAMEINUSE
		else {
			source->setNickname(parameters[0]);
			source->tryToRegister();
		}
	}
	else
		return; //FIXME send ERR_ERRONEUSNICKNAME
}

std::string NICK::arranger() {
	return (this->command);
}

bool NICK::validateNickname(std::string input) {
	size_t		i = 0;
	std::string	characters = "[]{}\\|";

	while (std::isalnum(input[i]) || characters.find(input[i]) != std::string::npos) {
		i++;
	}
	if (i != input.size())
		return (false);
	return (true);
}
