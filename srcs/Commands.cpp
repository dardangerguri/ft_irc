#include "Commands.hpp"

Commands::Commands(Server *s) {
	server = s;

	pass = std::shared_ptr<PASS>(new PASS(this));
	nick = std::shared_ptr<NICK>(new NICK(this));
	user = std::shared_ptr<USER>(new USER(this));
	rplWelcome = std::shared_ptr<RPL_WELCOME>(new RPL_WELCOME());
	rplYourHost = std::shared_ptr<RPL_YOURHOST>(new RPL_YOURHOST());
	rplCreated = std::shared_ptr<RPL_CREATED>(new RPL_CREATED());
	errNeedMoreParams = std::shared_ptr<ERR_NEEDMOREPARAMS>(new ERR_NEEDMOREPARAMS());
	errAlreadyRegistered = std::shared_ptr<ERR_ALREADYREGISTERED>(new ERR_ALREADYREGISTERED());
	errPasswMismatch = std::shared_ptr<ERR_PASSWDMISMATCH>(new ERR_PASSWDMISMATCH());
	errNoNicknameGiven = std::shared_ptr<ERR_NONICKNAMEGIVEN>(new ERR_NONICKNAMEGIVEN());
	errNicknameInUse = std::shared_ptr<ERR_NICKNAMEINUSE>(new ERR_NICKNAMEINUSE());
	errErroneusNickname = std::shared_ptr<ERR_ERRONEUSNICKNAME>(new ERR_ERRONEUSNICKNAME());

	commandList["PASS"] = this->pass;
	commandList["NICK"] = this->nick;
	commandList["USER"] = this->user;
}

Commands::~Commands() {
	commandList.clear();
}

void Commands::sendCommand(std::string message, Client *target) {
	// std::string response = BLUE "Sending this: " RESET;
    // response += message;
	// response += "\n";
	// std::cout << response;
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

void Commands::registrationReply(Client *target) {
	sendCommand(rplWelcome->arranger(target), target);
	sendCommand(rplYourHost->arranger(target), target);
	sendCommand(rplCreated->arranger(target), target);
	//FIXME call function to send the registration response to client
}

std::shared_ptr<ACommand> Commands::getCommandFromList(std::string command) {
	if (commandList.find(command) != commandList.end())
		return (commandList[command]);
	return (nullptr);
}
