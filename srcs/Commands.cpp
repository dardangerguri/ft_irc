#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	nick = std::shared_ptr<NICK>(new NICK(this));
	pass = std::shared_ptr<PASS>(new PASS(this));
	ping = std::shared_ptr<PING>(new PING(this));
	pong = std::shared_ptr<PONG>(new PONG(this));
	privMsg = std::shared_ptr<PRIVMSG>(new PRIVMSG(this));
	user = std::shared_ptr<USER>(new USER(this));

	rplWelcome = std::shared_ptr<RPL_WELCOME>(new RPL_WELCOME());
	rplYourHost = std::shared_ptr<RPL_YOURHOST>(new RPL_YOURHOST());
	rplCreated = std::shared_ptr<RPL_CREATED>(new RPL_CREATED());
	rplMyInfo = std::shared_ptr<RPL_MYINFO>(new RPL_MYINFO());
	rplISupport = std::shared_ptr<RPL_ISUPPORT>(new RPL_ISUPPORT());
	rplUModeIs = std::shared_ptr<RPL_UMODEIS>(new RPL_UMODEIS());
	rplLUserClient = std::shared_ptr<RPL_LUSERCLIENT>(new RPL_LUSERCLIENT(this));
	rplLUserMe = std::shared_ptr<RPL_LUSERME>(new RPL_LUSERME(this));

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
	errNotOnChannel = std::shared_ptr<ERR_NOTONCHANNEL>(new ERR_NOTONCHANNEL());
	errUserOnChannel = std::shared_ptr<ERR_USERONCHANNEL>(new ERR_USERONCHANNEL());
	errNotRegistered = std::shared_ptr<ERR_NOTREGISTERED>(new ERR_NOTREGISTERED());
	errNeedMoreParams = std::shared_ptr<ERR_NEEDMOREPARAMS>(new ERR_NEEDMOREPARAMS());
	errAlreadyRegistered = std::shared_ptr<ERR_ALREADYREGISTERED>(new ERR_ALREADYREGISTERED());
	errPasswMismatch = std::shared_ptr<ERR_PASSWDMISMATCH>(new ERR_PASSWDMISMATCH());
	errChanOPrivsNeeded = std::shared_ptr<ERR_CHANOPRIVSNEEDED>(new ERR_CHANOPRIVSNEEDED());

	try {
		commandList["NICK"] = this->nick;
		commandList["PASS"] = this->pass;
		commandList["PING"] = this->ping;
		commandList["PONG"] = this->pong;
		commandList["PRIVMSG"] = this->privMsg;
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
	//Debug
	std::cerr << BLUE "Sending: " RESET +  message << std::endl;

	message += "\r\n";
    if (send(target->getSocketFd(), message.c_str(), message.length(), 0) == -1) {
		std::cerr << RED << "Error: Sending messages failed!" << RESET << std::endl;
	}
}

void Commands::sendCommand(std::string message, Client *source, Client *target) {
	std::string response = ":" + source->getNickname() + " " + message + "\r\n";

	//Debug
	std::cerr << BLUE "Sending: " RESET + response << std::endl;

    if (send(target->getSocketFd(), response.c_str(), response.length(), 0) == -1) {
		std::cerr << RED << "Error: Sending messages failed!" << RESET << std::endl;
	}
}

void Commands::sendCommand(std::string message, Channel *target) {
	// send command to every client in channel
	(void)message;
	(void)target;
	return ;
}

void Commands::sendCommand(std::string message, Client *source, Channel *target) {
	// send command to every client in channel
	(void)source;
	(void)message;
	(void)target;
	return ;
}

//FIXME: check ISupport values
void Commands::registrationReply(Client *target) {
	sendCommand(rplWelcome->arranger(target), target);
	sendCommand(rplYourHost->arranger(target), target);
	sendCommand(rplCreated->arranger(target), target);
	sendCommand(rplMyInfo->arranger(target), target);
	sendCommand(rplISupport->arranger(target, "AWAYLEN=200"), target);
	sendCommand(rplISupport->arranger(target, "CASEMAPPING=rfc7613"), target);
	sendCommand(rplISupport->arranger(target, "CHANLIMIT=#&:50"), target);
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
	sendCommand(errNoMotd->arranger(target), target);
	sendCommand(rplUModeIs->arranger(target), target);
}

std::shared_ptr<ACommand> Commands::getCommandFromList(std::string command) {
	if (commandList.find(command) != commandList.end())
		return (commandList[command]);
	return (nullptr);
}
