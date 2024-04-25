#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	nick = std::shared_ptr<NICK>(new NICK(this));
	pass = std::shared_ptr<PASS>(new PASS(this));
	user = std::shared_ptr<USER>(new USER(this));

	rplWelcome = std::shared_ptr<RPL_WELCOME>(new RPL_WELCOME());
	rplYourHost = std::shared_ptr<RPL_YOURHOST>(new RPL_YOURHOST());
	rplCreated = std::shared_ptr<RPL_CREATED>(new RPL_CREATED());
	rplMyInfo = std::shared_ptr<RPL_MYINFO>(new RPL_MYINFO());
	rplISupport = std::shared_ptr<RPL_ISUPPORT>(new RPL_ISUPPORT());
	rplUModeIs = std::shared_ptr<RPL_UMODEIS>(new RPL_UMODEIS());
	rplLUserClient = std::shared_ptr<RPL_LUSERCLIENT>(new RPL_LUSERCLIENT(this));
	rplLUserMe = std::shared_ptr<RPL_LUSERME>(new RPL_LUSERME(this));

	errUnknownCommand = std::shared_ptr<ERR_UNKNOWNCOMMAND>(new ERR_UNKNOWNCOMMAND());
	errNoMotd = std::shared_ptr<ERR_NOMOTD>(new ERR_NOMOTD());
	errNoNicknameGiven = std::shared_ptr<ERR_NONICKNAMEGIVEN>(new ERR_NONICKNAMEGIVEN());
	errErroneusNickname = std::shared_ptr<ERR_ERRONEUSNICKNAME>(new ERR_ERRONEUSNICKNAME());
	errNicknameInUse = std::shared_ptr<ERR_NICKNAMEINUSE>(new ERR_NICKNAMEINUSE());
	errNotRegistered = std::shared_ptr<ERR_NOTREGISTERED>(new ERR_NOTREGISTERED());
	errNeedMoreParams = std::shared_ptr<ERR_NEEDMOREPARAMS>(new ERR_NEEDMOREPARAMS());
	errAlreadyRegistered = std::shared_ptr<ERR_ALREADYREGISTERED>(new ERR_ALREADYREGISTERED());
	errPasswMismatch = std::shared_ptr<ERR_PASSWDMISMATCH>(new ERR_PASSWDMISMATCH());

	commandList["NICK"] = this->nick;
	commandList["PASS"] = this->pass;
	commandList["USER"] = this->user;
}

Commands::~Commands() {
	commandList.clear();
}

void Commands::sendCommand(std::string message, Client *target) {
	//Debug
	std::cerr << BLUE "Sending: " RESET +  message << std::endl;

	message += "\r\n";
    send(target->getSocketFd(), message.c_str(), message.length(), 0);
}

void Commands::sendCommand(std::string message, Channel *target) {
	// send command to every client in channel
	(void)message;
	(void)target;
	return ;
}

void Commands::sendCommand(std::string message) {
	// send command to every client in server
	(void)message;
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
	sendCommand(rplISupport->arranger(target, "CHANMODES=b,k,l,imnpst"), target);
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
	sendCommand(rplISupport->arranger(target, "PREFIX=(ov)@+"), target);
	sendCommand(rplISupport->arranger(target, "SILENCE"), target);
	sendCommand(rplISupport->arranger(target, "STATUSMSG=@+"), target);
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
