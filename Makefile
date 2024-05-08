NAME    = ircserv
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++17 -fsanitize=address -g3
SRC_D   = srcs/
INC_D   = includes/
OBJ_D   = obj/

SRC     = 	main.cpp \
			Server.cpp \
			Client.cpp \
			Channel.cpp \
			Commands.cpp \
			Bot.cpp \
			commands/ACommand.cpp \
			commands/ERROR.cpp \
			commands/INVITE.cpp \
			commands/JOIN.cpp \
			commands/KICK.cpp \
			commands/MODE.cpp \
			commands/MOTD.cpp \
			commands/NAMES.cpp \
			commands/NICK.cpp \
			commands/OPER.cpp \
			commands/PART.cpp \
			commands/PASS.cpp \
			commands/PING.cpp \
			commands/PONG.cpp \
			commands/PRIVMSG.cpp \
			commands/QUIT.cpp \
			commands/TOPIC.cpp \
			commands/USER.cpp \
			commands/replies/RPL_WELCOME.cpp \
			commands/replies/RPL_YOURHOST.cpp \
			commands/replies/RPL_CREATED.cpp \
			commands/replies/RPL_MYINFO.cpp \
			commands/replies/RPL_ISUPPORT.cpp \
			commands/replies/RPL_UMODEIS.cpp \
			commands/replies/RPL_LUSERCLIENT.cpp \
			commands/replies/RPL_LUSERME.cpp \
			commands/replies/RPL_NOTOPIC.cpp \
			commands/replies/RPL_CHANNELMODEIS.cpp \
			commands/replies/RPL_TOPIC.cpp \
			commands/replies/RPL_TOPICWHOTIME.cpp \
			commands/replies/RPL_INVITING.cpp \
			commands/replies/RPL_NAMREPLY.cpp \
			commands/replies/RPL_ENDOFNAMES.cpp \
			commands/replies/RPL_MOTD.cpp \
			commands/replies/RPL_MOTDSTART.cpp \
			commands/replies/RPL_ENDOFMOTD.cpp \
			commands/replies/RPL_YOUREOPER.cpp \
			commands/errors/ERR_UNKNOWNERROR.cpp \
			commands/errors/ERR_NOSUCHNICK.cpp \
			commands/errors/ERR_NOSUCHCHANNEL.cpp \
			commands/errors/ERR_NORECIPIENT.cpp \
			commands/errors/ERR_NOTEXTTOSEND.cpp \
			commands/errors/ERR_UNKNOWNCOMMAND.cpp \
			commands/errors/ERR_NOMOTD.cpp \
			commands/errors/ERR_NONICKNAMEGIVEN.cpp \
			commands/errors/ERR_ERRONEUSNICKNAME.cpp \
			commands/errors/ERR_NICKNAMEINUSE.cpp \
			commands/errors/ERR_USERNOTINCHANNEL.cpp \
			commands/errors/ERR_NOTONCHANNEL.cpp \
			commands/errors/ERR_USERONCHANNEL.cpp \
			commands/errors/ERR_NOTREGISTERED.cpp \
			commands/errors/ERR_NEEDMOREPARAMS.cpp \
			commands/errors/ERR_ALREADYREGISTERED.cpp \
			commands/errors/ERR_PASSWDMISMATCH.cpp \
			commands/errors/ERR_CHANNELISFULL.cpp \
			commands/errors/ERR_UNKNOWNMODE.cpp \
			commands/errors/ERR_INVITEONLYCHAN.cpp \
			commands/errors/ERR_BADCHANNELKEY.cpp \
			commands/errors/ERR_BADCHANMASK.cpp \
			commands/errors/ERR_CHANOPRIVSNEEDED.cpp \
			commands/errors/ERR_NOOPERHOST.cpp \
			commands/errors/ERR_UMODEUNKNOWNFLAG.cpp \
			commands/errors/ERR_USERSDONTMATCH.cpp \
			commands/errors/ERR_INVALIDKEY.cpp \

OBJ_D   = obj/
OBJ     = $(SRC:.cpp=.o)
OBJS    = $(addprefix $(OBJ_D), $(OBJ))

INC     = -I$(INC_D) \
		  -I$(INC_D)commands/ \
		  -I$(INC_D)commands/errors \
		  -I$(INC_D)commands/replies

HEADERS = $(addprefix $(INC_D), $(filter-out main.hpp,$(SRC:.cpp=.hpp)))

all: $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.cpp $(HEADERS)
	mkdir -p $(OBJ_D)
	mkdir -p $(OBJ_D)commands
	mkdir -p $(OBJ_D)commands/errors
	mkdir -p $(OBJ_D)commands/replies
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
