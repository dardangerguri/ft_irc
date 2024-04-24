#include "ERR_NOTREGISTERED.hpp"

ERR_NOTREGISTERED::ERR_NOTREGISTERED(void) {
	command = "451";
}

ERR_NOTREGISTERED::~ERR_NOTREGISTERED(void) {
}

ERR_NOTREGISTERED &ERR_NOTREGISTERED::operator = (ERR_NOTREGISTERED const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_NOTREGISTERED::arranger(Client *source) {
	return (command + " " + source->getNickname() + " :You have not registered");
}
