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

std::string ERR_NEEDMOREPARAMS::arranger(std::string sourceCommand, Client *source) {
	return (command + " " + source->getNickname() + " " + sourceCommand + " :Not enough parameters");
}
