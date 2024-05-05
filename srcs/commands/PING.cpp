#include "PING.hpp"

PING::PING(Commands *c) {
	commands = c;
	command = "PING";
}

PING::~PING(void) {
}

PING &PING::operator = (PING const &copy) {
	(void)copy;
	return (*this);
}

void PING::handleCommand(std::string message, Client *source) {
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
	else {
		commands->sendCommand(commands->pong->arranger(parameters), source);
	}
}

// FIXME: temporary solution (need unique token?)
std::string PING::arranger() {
	return (this->command + " noot noot");
}
