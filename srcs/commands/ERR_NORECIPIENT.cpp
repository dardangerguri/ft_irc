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

std::string const ERR_NORECIPIENT::arranger(std::string const sourceCommand, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :No recipient given (" + sourceCommand + ")");
}
