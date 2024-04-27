#include "ERR_NORECIPIENT.hpp"

ERR_NORECIPIENT::ERR_NORECIPIENT(void) {
	command = "411";
}

ERR_NORECIPIENT::~ERR_NORECIPIENT(void) {
}

ERR_NORECIPIENT &ERR_NORECIPIENT::operator = (ERR_NORECIPIENT const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NORECIPIENT::arranger(std::string sourceCommand, Client *source) {
	return (command + " " + source->getNickname() + " :No recipient given (" + sourceCommand + ")");
}