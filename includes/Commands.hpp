#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include "ACommand.hpp"
# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include <unordered_map>
# include <memory>

class PASS;
class NICK;
class USER;
class RPL_WELCOME;
class RPL_YOURHOST;
class RPL_CREATED;
class RPL_MYINFO;
class RPL_ISUPPORT;
class RPL_LUSERCLIENT;
class RPL_LUSERME;
class ERR_NEEDMOREPARAMS;
class ERR_ALREADYREGISTERED;
class ERR_PASSWDMISMATCH;
class ERR_NONICKNAMEGIVEN;
class ERR_NICKNAMEINUSE;
class ERR_ERRONEUSNICKNAME;

class Commands {
	public:
		Server	*server;

		Commands(Server *s);
		~Commands();

		std::shared_ptr<ACommand> getCommandFromList(std::string command);
		void		sendCommand(std::string message, Client *target);
		void		sendCommand(std::string message, Channel *target);
		void		sendCommand(std::string message);
		void		registrationReply(Client *target);

		std::shared_ptr<PASS>					pass;
		std::shared_ptr<NICK>					nick;
		std::shared_ptr<USER>					user;
		std::shared_ptr<RPL_WELCOME>			rplWelcome;
		std::shared_ptr<RPL_YOURHOST>			rplYourHost;
		std::shared_ptr<RPL_CREATED>			rplCreated;
		std::shared_ptr<RPL_MYINFO>				rplMyInfo;
		std::shared_ptr<RPL_ISUPPORT>			rplISupport;
		std::shared_ptr<RPL_LUSERCLIENT>		rplLUserClient;
		std::shared_ptr<RPL_LUSERME>			rplLUserMe;
		std::shared_ptr<ERR_NEEDMOREPARAMS>		errNeedMoreParams;
		std::shared_ptr<ERR_ALREADYREGISTERED>	errAlreadyRegistered;
		std::shared_ptr<ERR_PASSWDMISMATCH>		errPasswMismatch;
		std::shared_ptr<ERR_NONICKNAMEGIVEN>	errNoNicknameGiven;
		std::shared_ptr<ERR_NICKNAMEINUSE>		errNicknameInUse;
		std::shared_ptr<ERR_ERRONEUSNICKNAME>	errErroneusNickname;

	private:
		Commands();
		Commands(Commands &copy);
		Commands &operator = (Commands &copy);

		std::unordered_map<std::string, std::shared_ptr<ACommand>>	commandList;
};

# include "PASS.hpp"
# include "NICK.hpp"
# include "USER.hpp"
# include "RPL_WELCOME.hpp"
# include "RPL_YOURHOST.hpp"
# include "RPL_CREATED.hpp"
# include "RPL_MYINFO.hpp"
# include "RPL_ISUPPORT.hpp"
# include "RPL_LUSERCLIENT.hpp"
# include "RPL_LUSERME.hpp"
# include "ERR_NEEDMOREPARAMS.hpp"
# include "ERR_ALREADYREGISTERED.hpp"
# include "ERR_PASSWDMISMATCH.hpp"
# include "ERR_NONICKNAMEGIVEN.hpp"
# include "ERR_NICKNAMEINUSE.hpp"
# include "ERR_ERRONEUSNICKNAME.hpp"

#endif
