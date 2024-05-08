#include "ERR_NOTEXTTOSEND.hpp"

ERR_NOTEXTTOSEND::ERR_NOTEXTTOSEND(void) {
	command = "412";
}

ERR_NOTEXTTOSEND::~ERR_NOTEXTTOSEND(void) {
}

ERR_NOTEXTTOSEND &ERR_NOTEXTTOSEND::operator = (ERR_NOTEXTTOSEND const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_NOTEXTTOSEND::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :No text to send");
}
