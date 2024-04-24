#include "ERR_UNKNOWNCOMMAND.hpp"

ERR_UNKNOWNCOMMAND::ERR_UNKNOWNCOMMAND(void) {
	command = "421";
}

ERR_UNKNOWNCOMMAND::~ERR_UNKNOWNCOMMAND(void) {
}

ERR_UNKNOWNCOMMAND &ERR_UNKNOWNCOMMAND::operator = (ERR_UNKNOWNCOMMAND const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_UNKNOWNCOMMAND::arranger(std::string sourceCommand, Client *source) {
	return (command + " " + source->getNickname() \
	+ " " + sourceCommand + " :Unknown command");
}
