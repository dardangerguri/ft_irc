#include "QUIT.hpp"

QUIT::QUIT(Commands *c) {
	commands = c;
	command = "QUIT";
}

QUIT::~QUIT(void) {
}

QUIT &QUIT::operator = (QUIT const &copy) {
	(void)copy;
	return (*this);
}

void QUIT::handleCommand(std::string message, Client *source) {
	if (!message.empty() && message[0] == ':')
		message.erase(0, 1);
	for (std::pair<std::string, Channel *> chanPair : source->getJoinedChannels()) {
		commands->sendCommand(arranger("Quit: " + message), source, chanPair.second);
		chanPair.second->userLeave(source);
	}
	commands->sendCommand(commands->error->arranger("Connection closed: Lost connection to client"), source);
}

std::string QUIT::arranger(std::string message) {
	return (this->command + ":" + message);
}
