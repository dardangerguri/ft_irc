#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include "ACommand.hpp"
# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"
# include <unordered_map>
# include <memory>

class INVITE;
class NICK;
class PASS;
class PING;
class PONG;
class PRIVMSG;
class TOPIC;
class USER;

class RPL_WELCOME; //001
class RPL_YOURHOST; //002
class RPL_CREATED; //003
class RPL_MYINFO; //004
class RPL_ISUPPORT; //005
class RPL_UMODEIS; //221
class RPL_LUSERCLIENT; //251
class RPL_LUSERME; //255
class RPL_NOTOPIC; //331
class RPL_INVITING; //341

class ERR_UNKNOWNERROR; //400
class ERR_NOSUCHNICK; //401
class ERR_NOSUCHCHANNEL; //403
class ERR_NORECIPIENT; //411
class ERR_NOTEXTTOSEND; //412
class ERR_UNKNOWNCOMMAND; //421
class ERR_NOMOTD; //422
class ERR_NONICKNAMEGIVEN; //431
class ERR_ERRONEUSNICKNAME; //432
class ERR_NICKNAMEINUSE; //433
class ERR_NOTONCHANNEL; //442
class ERR_USERONCHANNEL; //443
class ERR_NOTREGISTERED; //451
class ERR_NEEDMOREPARAMS; //461
class ERR_ALREADYREGISTERED; //462
class ERR_PASSWDMISMATCH; //464
class ERR_CHANOPRIVSNEEDED; //482

class Commands {
	public:
		Server	*server;

		Commands(Server *s);
		~Commands();

		std::shared_ptr<ACommand> getCommandFromList(std::string command);
		void		sendCommand(std::string message, Client *target);
		void		sendCommand(std::string message, Client *source, Client *target);
		void		sendCommand(std::string message, Channel *target);
		void		sendCommand(std::string message, Client *source, Channel *target);
		void		registrationReply(Client *target);

		std::shared_ptr<INVITE>					invite;
		std::shared_ptr<NICK>					nick;
		std::shared_ptr<PASS>					pass;
		std::shared_ptr<PING>					ping;
		std::shared_ptr<PONG>					pong;
		std::shared_ptr<PRIVMSG>				privMsg;
		std::shared_ptr<TOPIC>					topic;
		std::shared_ptr<USER>					user;

		std::shared_ptr<RPL_WELCOME>			rplWelcome;
		std::shared_ptr<RPL_YOURHOST>			rplYourHost;
		std::shared_ptr<RPL_CREATED>			rplCreated;
		std::shared_ptr<RPL_MYINFO>				rplMyInfo;
		std::shared_ptr<RPL_ISUPPORT>			rplISupport;
		std::shared_ptr<RPL_UMODEIS>			rplUModeIs;
		std::shared_ptr<RPL_LUSERCLIENT>		rplLUserClient;
		std::shared_ptr<RPL_LUSERME>			rplLUserMe;
		std::shared_ptr<RPL_NOTOPIC>			rplNoTopic;
		std::shared_ptr<RPL_INVITING>			rplInviting;

		std::shared_ptr<ERR_UNKNOWNERROR>		errUnknownError;
		std::shared_ptr<ERR_NOSUCHNICK>			errNoSuchNick;
		std::shared_ptr<ERR_NOSUCHCHANNEL>		errNoSuchChannel;
		std::shared_ptr<ERR_NORECIPIENT>		errNoRecipient;
		std::shared_ptr<ERR_NOTEXTTOSEND>		errNoTextToSend;
		std::shared_ptr<ERR_UNKNOWNCOMMAND>		errUnknownCommand;
		std::shared_ptr<ERR_NOMOTD>				errNoMotd;
		std::shared_ptr<ERR_NONICKNAMEGIVEN>	errNoNicknameGiven;
		std::shared_ptr<ERR_ERRONEUSNICKNAME>	errErroneusNickname;
		std::shared_ptr<ERR_NICKNAMEINUSE>		errNicknameInUse;
		std::shared_ptr<ERR_NOTONCHANNEL>		errNotOnChannel;
		std::shared_ptr<ERR_USERONCHANNEL>		errUserOnChannel;
		std::shared_ptr<ERR_NOTREGISTERED>		errNotRegistered;
		std::shared_ptr<ERR_NEEDMOREPARAMS>		errNeedMoreParams;
		std::shared_ptr<ERR_ALREADYREGISTERED>	errAlreadyRegistered;
		std::shared_ptr<ERR_PASSWDMISMATCH>		errPasswMismatch;
		std::shared_ptr<ERR_CHANOPRIVSNEEDED>	errChanOPrivsNeeded;

	private:
		Commands();
		Commands(Commands &copy);
		Commands &operator = (Commands &copy);

		std::unordered_map<std::string, std::shared_ptr<ACommand>>	commandList;
};

# include "INVITE.hpp"
# include "NICK.hpp"
# include "PASS.hpp"
# include "PING.hpp"
# include "PONG.hpp"
# include "PRIVMSG.hpp"
# include "TOPIC.hpp"
# include "USER.hpp"

# include "RPL_WELCOME.hpp"
# include "RPL_YOURHOST.hpp"
# include "RPL_CREATED.hpp"
# include "RPL_MYINFO.hpp"
# include "RPL_ISUPPORT.hpp"
# include "RPL_UMODEIS.hpp"
# include "RPL_LUSERCLIENT.hpp"
# include "RPL_LUSERME.hpp"
# include "RPL_NOTOPIC.hpp"
# include "RPL_INVITING.hpp"

# include "ERR_UNKNOWNERROR.hpp"
# include "ERR_NOSUCHNICK.hpp"
# include "ERR_NOSUCHCHANNEL.hpp"
# include "ERR_NORECIPIENT.hpp"
# include "ERR_NOTEXTTOSEND.hpp"
# include "ERR_UNKNOWNCOMMAND.hpp"
# include "ERR_NOMOTD.hpp"
# include "ERR_NONICKNAMEGIVEN.hpp"
# include "ERR_ERRONEUSNICKNAME.hpp"
# include "ERR_NICKNAMEINUSE.hpp"
# include "ERR_NOTONCHANNEL.hpp"
# include "ERR_USERONCHANNEL.hpp"
# include "ERR_NOTREGISTERED.hpp"
# include "ERR_NEEDMOREPARAMS.hpp"
# include "ERR_ALREADYREGISTERED.hpp"
# include "ERR_PASSWDMISMATCH.hpp"
# include "ERR_CHANOPRIVSNEEDED.hpp"

#endif
