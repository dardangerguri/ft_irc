#include "ERR_USERSDONTMATCH.hpp"

ERR_USERSDONTMATCH::ERR_USERSDONTMATCH(void) {
	command = "502";
}

ERR_USERSDONTMATCH::~ERR_USERSDONTMATCH(void) {
}

ERR_USERSDONTMATCH &ERR_USERSDONTMATCH::operator = (ERR_USERSDONTMATCH const &copy) {
	(void)copy;
	return (*this);
}

std::string ERR_USERSDONTMATCH::arranger(Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " :Cant change mode for other users");
}
