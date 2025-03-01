#include "PASS.hpp"

PASS::PASS(Commands *c) {
	commands = c;
	command = "PASS";
	requireRegistration = false;
}

PASS::~PASS(void) {
}

PASS &PASS::operator = (PASS const &copy) {
	(void)copy;
	return (*this);
}

void PASS::handleCommand(std::string const message, Client *source) {
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
	else if (source->hasMode('r'))
		commands->sendCommand(commands->errAlreadyRegistered->arranger(source), source);
	else if (commands->server->checkPassword(parameters[0])) {
		source->setValidPass();
		if (source->tryToRegister())
			commands->registrationReply(source);
	}
	else
		commands->sendCommand(commands->errPasswMismatch->arranger(source), source);
}

std::string const PASS::arranger() const {
	return (this->command);
}
