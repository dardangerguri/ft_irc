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

std::string ERR_NOTREGISTERED::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :You have not registered");
}
