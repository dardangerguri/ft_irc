#include "PONG.hpp"

PONG::PONG(Commands *c) {
	commands = c;
	command = "PONG";
}

PONG::~PONG(void) {
}

PONG &PONG::operator = (PONG const &copy) {
	(void)copy;
	return (*this);
}

void PONG::handleCommand(std::string message, Client *source) {
	(void)message;
	(void)source;
}

std::string PONG::arranger(std::vector<std::string> parameters) {
	return ("PONG 127.0.0.1 " + parameters[0]);
}
