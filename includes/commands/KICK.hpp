#ifndef KICK_HPP
# define KICK_HPP

# include "ACommand.hpp"

class KICK : public ACommand {
	public:
		KICK(Commands *c);
		~KICK(void);

		KICK &operator=(KICK const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(Channel *channel, Client *removedUser, std::string reason);

	private:
		KICK(void);
		KICK(KICK const &copy);

		std::vector<std::string> parseMessage(std::string message);
};

#endif