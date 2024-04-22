NAME    = ircserv
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++17 -fsanitize=address -g3
SRC_D   = srcs/
INC_D   = includes/
OBJ_D   = obj/

SRC     = main.cpp Server.cpp Client.cpp Channel.cpp Commands.cpp \
		./commands/ACommand.cpp ./commands/PASS.cpp ./commands/NICK.cpp \
		./commands/ERR_NEEDMOREPARAMS.cpp ./commands/USER.cpp

OBJ_D   = obj/
OBJ     = $(SRC:.cpp=.o)
OBJS    = $(addprefix $(OBJ_D), $(OBJ))

INC     = -I$(INC_D) -I$(INC_D)commands/

HEADERS = $(INC_D)/Server.hpp $(INC_D)/Client.hpp $(INC_D)/Channel.hpp $(INC_D)/Commands.hpp \
          $(INC_D)/commands/ACommand.hpp $(INC_D)/commands/PASS.hpp $(INC_D)/commands/USER.hpp \
		  $(INC_D)/commands/NICK.hpp \
		  $(INC_D)/commands/ERR_NEEDMOREPARAMS.hpp

all: $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.cpp $(HEADERS)
	mkdir -p $(OBJ_D)
	mkdir -p $(OBJ_D)commands
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
