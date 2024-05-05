#include "OPER.hpp"

OPER::OPER(Commands *c) {
	commands = c;
	command = "OPER";
}

OPER::~OPER(void) {
}

OPER &OPER::operator = (OPER const &copy) {
	(void)copy;
	return (*this);
}

void OPER::handleCommand(std::string message, Client *source) {
	std::vector<std::string>	parameters;

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
		if (parameters[0] != operName || parameters[1] != operPasswd)
			commands->sendCommand(commands->errPasswMismatch->arranger(source), source);
		else if (strcmp(source->getIp(), validHost))
			commands->sendCommand(commands->errNoOperHost->arranger(source), source);
		else {
			source->addMode('o');
			commands->sendCommand(commands->rplYouReOper->arranger(source), source);
			commands->sendCommand(commands->mode->arranger("+o", source), source);
		}
	}
}

std::string OPER::arranger() {
	return (this->command);
}
