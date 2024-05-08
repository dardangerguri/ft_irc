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
		if (chanPair.second->getUserCount() == 0)
			commands->server->delChannel(chanPair.second);
	}
	commands->sendCommand(commands->error->arranger("Connection closed: Lost connection to client"), source);
}

std::string const QUIT::arranger(std::string const message) const {
	return (this->command + " :" + message);
}
