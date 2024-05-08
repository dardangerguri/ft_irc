#include "ERR_NEEDMOREPARAMS.hpp"

ERR_NEEDMOREPARAMS::ERR_NEEDMOREPARAMS(void) {
	command = "461";
}

ERR_NEEDMOREPARAMS::~ERR_NEEDMOREPARAMS(void) {
}

ERR_NEEDMOREPARAMS &ERR_NEEDMOREPARAMS::operator = (ERR_NEEDMOREPARAMS const &copy) {
	(void)copy;
	return (*this);
}

std::string const ERR_NEEDMOREPARAMS::arranger(std::string const sourceCommand, Client *source) const {
	std::string	nickname;

	if (source)
		nickname = source->getNickname();

	return (command + " " + nickname + " " + sourceCommand + " :Not enough parameters");
}
