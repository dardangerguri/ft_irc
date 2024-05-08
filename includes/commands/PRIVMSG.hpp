#ifndef PRIVMSG_HPP
# define PRIVMSG_HPP

# include "ACommand.hpp"

class PRIVMSG : public ACommand {
	public:
		PRIVMSG(Commands *c);
		~PRIVMSG(void);

		PRIVMSG &operator=(PRIVMSG const &copy);

		void				handleCommand(std::string const message, Client *source);
		std::string const	arranger(Client *target, std::string const message) const;
		std::string const	arranger(Channel *target, std::string const message) const;

	private:
		PRIVMSG(void);
		PRIVMSG(PRIVMSG const &copy);

		std::vector<std::string>	parseMessage(std::string const message) const;
};

#endif
