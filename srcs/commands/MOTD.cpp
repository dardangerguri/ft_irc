#include "MOTD.hpp"

MOTD::MOTD(Commands *c) {
	commands = c;
	command = "MOTD";
}

MOTD::~MOTD(void) {
}

MOTD &MOTD::operator = (MOTD const &copy) {
	(void)copy;
	return (*this);
}

void MOTD::handleCommand(std::string message, Client *source) {
	(void)message;

	std::vector<std::string>	motd = {
	"  ___ ___  ___   ___  _____   _____",
	" |_ _| _ \\/ __| | _ )/ _ \\ \\ / / __|",
	"  | ||   / (__  | _ \\ (_) \\ V /\\__ \\",
	" |___|_|_\\\\___| |___/\\___/ |_| |___/",
	"                                    "
	};

	commands->sendCommand(commands->rplMotdStart->arranger(source), source);
	for (std::string line : motd) {
		commands->sendCommand(commands->rplMotd->arranger(source, line), source);
	}
	commands->sendCommand(commands->rplEndOfMotd->arranger(source), source);
}

std::string MOTD::arranger() {
	return (this->command);
}
