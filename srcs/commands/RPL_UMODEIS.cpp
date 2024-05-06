#include "RPL_UMODEIS.hpp"

RPL_UMODEIS::RPL_UMODEIS(void) {
	command = "221";
}

RPL_UMODEIS::~RPL_UMODEIS(void) {
}

RPL_UMODEIS &RPL_UMODEIS::operator = (RPL_UMODEIS const &copy) {
	(void)copy;
	return (*this);
}

std::string RPL_UMODEIS::arranger(Client *source) {
	std::unordered_set<char> supportedModes = {'o', 'r', 'i', 'O', 'w'};
	std::string modes;
	std::string	nickname;

	if (source) {
		nickname = source->getNickname();
		for (char mode : supportedModes) {
			if (source->hasMode(mode))
				modes += mode;
		}
	}

	return (command + " " + nickname + " " + modes);
}
