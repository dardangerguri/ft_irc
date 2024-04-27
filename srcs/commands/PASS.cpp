#include "PASS.hpp"
#include "ERR_NEEDMOREPARAMS.hpp"

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

void PASS::handleCommand(std::string message, Client *source) {
	std::vector<std::string> parameters;
	if (!message.empty())
		parameters = parseMessage(message, source);

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

std::string PASS::arranger() {
	return (this->command);
}
