#include "RPL_ISUPPORT.hpp"

RPL_ISUPPORT::RPL_ISUPPORT(void) {
	command = "005";
}

RPL_ISUPPORT::~RPL_ISUPPORT(void) {
}

RPL_ISUPPORT &RPL_ISUPPORT::operator = (RPL_ISUPPORT const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_ISUPPORT::arranger(Client *source, std::string const token) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + token + " :are supported by this server");
}
