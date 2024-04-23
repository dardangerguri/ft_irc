#include "ERR_NOMOTD.hpp"

ERR_NOMOTD::ERR_NOMOTD(void) {
	command = "422";
}

ERR_NOMOTD::~ERR_NOMOTD(void) {
}

ERR_NOMOTD &ERR_NOMOTD::operator = (ERR_NOMOTD const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOMOTD::arranger(Client *source) {
	return (command + " " + source->getNickname() + " :MOTD File is missing");
}
