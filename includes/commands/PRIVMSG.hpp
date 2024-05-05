#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "ACommand.hpp"

class PRIVMSG : public ACommand {
	public:
		PRIVMSG(Commands *c);
		~PRIVMSG(void);

		PRIVMSG &operator=(PRIVMSG const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(Client *target, std::string message);
		std::string	arranger(Channel *target, std::string message);

	private:
		PRIVMSG(void);
		PRIVMSG(PRIVMSG const &copy);

		std::vector<std::string>	parseMessage(std::string message);
};

#endif
