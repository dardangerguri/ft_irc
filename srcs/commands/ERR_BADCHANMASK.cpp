#include "ERR_BADCHANMASK.hpp"

ERR_BADCHANMASK::ERR_BADCHANMASK(void) {
	command = "476";
}

ERR_BADCHANMASK::~ERR_BADCHANMASK(void) {
}

ERR_BADCHANMASK &ERR_BADCHANMASK::operator = (ERR_BADCHANMASK const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_BADCHANMASK::arranger(std::string const channel) const {
	return (command + " " + channel + " :Bad Channel Mask");
}
