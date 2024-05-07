#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	error =  std::shared_ptr<ERROR>(new ERROR(this));
	invite = std::shared_ptr<INVITE>(new INVITE(this));
	join = std::shared_ptr<JOIN>(new JOIN(this));
	kick = std::shared_ptr<KICK>(new KICK(this));
	mode = std::shared_ptr<MODE>(new MODE(this));
	motd = std::shared_ptr<MOTD>(new MOTD(this));
	names = std::shared_ptr<NAMES>(new NAMES(this));
	nick = std::shared_ptr<NICK>(new NICK(this));
	part = std::shared_ptr<PART>(new PART(this));
	pass = std::shared_ptr<PASS>(new PASS(this));
	ping = std::shared_ptr<PING>(new PING(this));
	pong = std::shared_ptr<PONG>(new PONG(this));
	privMsg = std::shared_ptr<PRIVMSG>(new PRIVMSG(this));
	quit = std::shared_ptr<QUIT>(new QUIT(this));
	topic = std::shared_ptr<TOPIC>(new TOPIC(this));
	user = std::shared_ptr<USER>(new USER(this));

	rplWelcome = std::shared_ptr<RPL_WELCOME>(new RPL_WELCOME());
	rplYourHost = std::shared_ptr<RPL_YOURHOST>(new RPL_YOURHOST());
	rplCreated = std::shared_ptr<RPL_CREATED>(new RPL_CREATED());
	rplMyInfo = std::shared_ptr<RPL_MYINFO>(new RPL_MYINFO());
	rplISupport = std::shared_ptr<RPL_ISUPPORT>(new RPL_ISUPPORT());
	rplUModeIs = std::shared_ptr<RPL_UMODEIS>(new RPL_UMODEIS());
	rplLUserClient = std::shared_ptr<RPL_LUSERCLIENT>(new RPL_LUSERCLIENT(this));
	rplLUserMe = std::shared_ptr<RPL_LUSERME>(new RPL_LUSERME(this));
	rplChannelModeIs = std::shared_ptr<RPL_CHANNELMODEIS>(new RPL_CHANNELMODEIS());
	rplNoTopic = std::shared_ptr<RPL_NOTOPIC>(new RPL_NOTOPIC());
	rplTopic = std::shared_ptr<RPL_TOPIC>(new RPL_TOPIC());
	rplTopicWhoTime = std::shared_ptr<RPL_TOPICWHOTIME>(new RPL_TOPICWHOTIME());
	rplInviting = std::shared_ptr<RPL_INVITING>(new RPL_INVITING());
	rplNamReply = std::shared_ptr<RPL_NAMREPLY>(new RPL_NAMREPLY());
	rplEndOfNames = std::shared_ptr<RPL_ENDOFNAMES>(new RPL_ENDOFNAMES());
	rplMotd = std::shared_ptr<RPL_MOTD>(new RPL_MOTD());
	rplMotdStart = std::shared_ptr<RPL_MOTDSTART>(new RPL_MOTDSTART());
	rplEndOfMotd = std::shared_ptr<RPL_ENDOFMOTD>(new RPL_ENDOFMOTD());

	errUnknownError = std::shared_ptr<ERR_UNKNOWNERROR>(new ERR_UNKNOWNERROR());
	errNoSuchNick = std::shared_ptr<ERR_NOSUCHNICK>(new ERR_NOSUCHNICK());
	errNoSuchChannel = std::shared_ptr<ERR_NOSUCHCHANNEL>(new ERR_NOSUCHCHANNEL());
	errNoRecipient = std::shared_ptr<ERR_NORECIPIENT>(new ERR_NORECIPIENT());
	errNoTextToSend = std::shared_ptr<ERR_NOTEXTTOSEND>(new ERR_NOTEXTTOSEND());
	errUnknownCommand = std::shared_ptr<ERR_UNKNOWNCOMMAND>(new ERR_UNKNOWNCOMMAND());
	errNoMotd = std::shared_ptr<ERR_NOMOTD>(new ERR_NOMOTD());
	errNoNicknameGiven = std::shared_ptr<ERR_NONICKNAMEGIVEN>(new ERR_NONICKNAMEGIVEN());
	errErroneusNickname = std::shared_ptr<ERR_ERRONEUSNICKNAME>(new ERR_ERRONEUSNICKNAME());
	errNicknameInUse = std::shared_ptr<ERR_NICKNAMEINUSE>(new ERR_NICKNAMEINUSE());
	errUserNotInChannel = std::shared_ptr<ERR_USERNOTINCHANNEL>(new ERR_USERNOTINCHANNEL());
	errNotOnChannel = std::shared_ptr<ERR_NOTONCHANNEL>(new ERR_NOTONCHANNEL());
	errUserOnChannel = std::shared_ptr<ERR_USERONCHANNEL>(new ERR_USERONCHANNEL());
	errNotRegistered = std::shared_ptr<ERR_NOTREGISTERED>(new ERR_NOTREGISTERED());
	errNeedMoreParams = std::shared_ptr<ERR_NEEDMOREPARAMS>(new ERR_NEEDMOREPARAMS());
	errAlreadyRegistered = std::shared_ptr<ERR_ALREADYREGISTERED>(new ERR_ALREADYREGISTERED());
	errPasswMismatch = std::shared_ptr<ERR_PASSWDMISMATCH>(new ERR_PASSWDMISMATCH());
	errChannelIsFull = std::shared_ptr<ERR_CHANNELISFULL>(new ERR_CHANNELISFULL());
	errUnknownMode = std::shared_ptr<ERR_UNKNOWNMODE>(new ERR_UNKNOWNMODE());
	errInviteOnlyChan = std::shared_ptr<ERR_INVITEONLYCHAN>(new ERR_INVITEONLYCHAN());
	errBadChannelKey = std::shared_ptr<ERR_BADCHANNELKEY>(new ERR_BADCHANNELKEY());
	errBadChanMask = std::shared_ptr<ERR_BADCHANMASK>(new ERR_BADCHANMASK());
	errChanOPrivsNeeded = std::shared_ptr<ERR_CHANOPRIVSNEEDED>(new ERR_CHANOPRIVSNEEDED());
	errUModeUnknownFlag = std::shared_ptr<ERR_UMODEUNKNOWNFLAG>(new ERR_UMODEUNKNOWNFLAG());
	errUsersDontMatch = std::shared_ptr<ERR_USERSDONTMATCH>(new ERR_USERSDONTMATCH());
	errInvalidKey = std::shared_ptr<ERR_INVALIDKEY>(new ERR_INVALIDKEY());

	try {
		commandList["ERROR"] = this->error;
		commandList["INVITE"] = this->invite;
		commandList["JOIN"] = this->join;
		commandList["KICK"] = this->kick;
		commandList["MODE"] = this->mode;
		commandList["MOTD"] = this->motd;
		commandList["NAMES"] = this->names;
		commandList["NICK"] = this->nick;
		commandList["PART"] = this->part;
		commandList["PASS"] = this->pass;
		commandList["PING"] = this->ping;
		commandList["PONG"] = this->pong;
		commandList["PRIVMSG"] = this->privMsg;
		commandList["QUIT"] = this->quit;
		commandList["TOPIC"] = this->topic;
		commandList["USER"] = this->user;
	}
	catch (std::exception &e) {
		throw std::runtime_error("Could not add the command to the commandList!");
	}
}

Commands::~Commands() {
	commandList.clear();
}

void Commands::sendCommand(std::string message, Client *target) {
	if (target) {
		//Debug
		std::cerr << BLUE "Sending: " RESET +  message << std::endl;

		message += "\r\n";
		if (send(target->getSocketFd(), message.c_str(), message.length(), 0) == -1) {
			std::cerr << RED << "Error: Sending messages failed!" << RESET << std::endl;
		}
	}
}

void Commands::sendCommand(std::string message, Client *source, Client *target) {
	sendCommand(":" + source->getNickname() + " " + message, target);
}

void Commands::sendCommand(std::string message, Channel *target) {
	if (target) {
		//Debug
		std::cerr << BLUE "Sending to " RESET + target->getName() + BLUE ": " RESET + message << std::endl;

		message += "\r\n";
		for (Client *user : target->getUserList()) {
			if (send(user->getSocketFd(), message.c_str(), message.length(), 0) == -1) {
				std::cerr << RED << "Error: Sending message to " RESET + user->getNickname() + RED " failed!" << RESET << std::endl;
			}
		}
	}
}

void Commands::sendCommand(std::string message, Client *source, Channel *target) {
	sendCommand(":" + source->getNickname() + " " + message, target);
}

void Commands::sendCommand(std::string message, Channel *target, Client *exclude) {
	if (target && exclude) {
		//Debug
		std::cerr << BLUE "Sending to " RESET + target->getName() + BLUE " excluding user " RESET + exclude->getNickname() + BLUE ": " RESET + message << std::endl;

		message += "\r\n";
		for (Client *user : target->getUserList()) {
			if (user == exclude)
				continue ;
			if (send(user->getSocketFd(), message.c_str(), message.length(), 0) == -1) {
				std::cerr << RED << "Error: Sending message to " RESET + user->getNickname() + RED " failed!" << RESET << std::endl;
			}
		}
	}
}

void Commands::sendCommand(std::string message, Client *source, Channel *target, Client *exclude) {
	sendCommand(":" + source->getNickname() + " " + message, target, exclude);
}

//FIXME: check ISupport values
void Commands::registrationReply(Client *target) {
	if (target) {
		sendCommand(rplWelcome->arranger(target), target);
		sendCommand(rplYourHost->arranger(target), target);
		sendCommand(rplCreated->arranger(target), target);
		sendCommand(rplMyInfo->arranger(target), target);
		sendCommand(rplISupport->arranger(target, "AWAYLEN=200"), target);
		sendCommand(rplISupport->arranger(target, "CASEMAPPING=rfc7613"), target);
		sendCommand(rplISupport->arranger(target, "CHANLIMIT=#:"), target);
		sendCommand(rplISupport->arranger(target, "CHANMODES=,k,l,it"), target);
		sendCommand(rplISupport->arranger(target, "CHANNELLEN=32"), target);
		sendCommand(rplISupport->arranger(target, "CHANTYPES=#"), target);
		sendCommand(rplISupport->arranger(target, "ELIST="), target);
		sendCommand(rplISupport->arranger(target, "EXCEPTS"), target);
		sendCommand(rplISupport->arranger(target, "EXTBAN="), target);
		sendCommand(rplISupport->arranger(target, "HOSTLEN=64"), target);
		sendCommand(rplISupport->arranger(target, "INVEX"), target);
		sendCommand(rplISupport->arranger(target, "KICKLEN=255"), target);
		sendCommand(rplISupport->arranger(target, "MAXLIST=beI:25"), target);
		sendCommand(rplISupport->arranger(target, "MAXTARGETS=1"), target);
		sendCommand(rplISupport->arranger(target, "MODES=12"), target);
		sendCommand(rplISupport->arranger(target, "NETWORK=IRC\x20\\BOYS\x20Network"), target);
		sendCommand(rplISupport->arranger(target, "NICKLEN=12"), target);
		sendCommand(rplISupport->arranger(target, "PREFIX=(o)@"), target);
		sendCommand(rplISupport->arranger(target, "SILENCE"), target);
		sendCommand(rplISupport->arranger(target, "STATUSMSG=@"), target);
		sendCommand(rplISupport->arranger(target, "TOPICLEN=307"), target);
		sendCommand(rplISupport->arranger(target, "USERLEN=12"), target);
		sendCommand(rplLUserClient->arranger(target), target);
		sendCommand(rplLUserMe->arranger(target), target);
		motd->handleCommand("", target);
		sendCommand(rplUModeIs->arranger(target), target);
	}
}

void Commands::namesReply(Client *source, Channel *channel) {
	if (source && channel) {
		for (Client *user : channel->getUserList()) {
			sendCommand(rplNamReply->arranger(source, channel, user), source);
		}
		sendCommand(rplEndOfNames->arranger(source, channel), source);
	}
}

std::shared_ptr<ACommand> Commands::getCommandFromList(std::string command) {
	if (commandList.find(command) != commandList.end())
		return (commandList[command]);
	return (nullptr);
}
