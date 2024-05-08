#include "Bot.hpp"

Bot::Bot(Commands *c) : Client(-1) {
	this->commands = c;
	this->setNickname("SanicBot");
}

Bot::~Bot(void) {
}

Bot &Bot::operator = (Bot const &copy) {
	(void)copy;
	return (*this);
}

void Bot::handleBotMessage(std::string const message, Channel *target) {
	if (!target)
		return ;

	std::string					channel = target->getName();
	std::string					reply;
	std::vector<std::string>	parameters;
	std::stringstream			ss(message);
	std::string					word;

	while (ss >> word) {
		parameters.push_back(word);
	}

	if (parameters[1] == "JOIN" && parameters.size() == 3){
		std::string	nick = parameters[0].erase(0, 1);

		reply = "Welcome to " + channel + ", " + nick + "!";

		if (target->getUserCount() == 2)
			commands->mode->handleCommand(channel + " +o " + nick, this);
	}
	else if (parameters[1] == "PRIVMSG" && parameters[3] == ":!joke")
		reply = getJoke();
	else if (parameters[1] == "PRIVMSG" && parameters[3] == ":!gtfo")
		commands->part->handleCommand(channel + " :Good bye!", this);
	else if (parameters[1] == "PART" && parameters[0] != ":" + this->getNickname()) {
		if (target->getUserCount() == 2)
			commands->part->handleCommand(channel + " :Good bye!" , this);
	}

	if (!reply.empty())
		commands->sendCommand(commands->privMsg->arranger(target, reply), this, target, this);
}

void Bot::handleBotMessage(std::string const message, Client *target) {
	(void)message;
	(void)target;
	return ;
}

std::string const	Bot::getJoke(void) const {
	std::vector<std::string> const jokes = {
		"What do you call IRC operator cleaning floors? - A moperator",
		"How do you get IRC user to visit? - You INVITE them"
	};

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, jokes.size() - 1);

	return (jokes[distr(gen)]);
}
