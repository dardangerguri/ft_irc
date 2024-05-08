#include "ERROR.hpp"

ERROR::ERROR(Commands *c) {
	commands = c;
	command = "ERROR";
}

ERROR::~ERROR(void) {
}

ERROR &ERROR::operator = (ERROR const &copy) {
	(void)copy;
	return (*this);
}

void ERROR::handleCommand(std::string const message, Client *source) {
	(void)message;
	(void)source;
}

std::string ERROR::arranger(std::string message) const {
	return (this->command + " :" + message);
}
