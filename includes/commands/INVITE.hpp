#ifndef INVITE_HPP
# define INVITE_HPP

# include "ACommand.hpp"

class INVITE : public ACommand {
	public:
		INVITE(Commands *c);
		~INVITE(void);

		INVITE &operator=(INVITE const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(Client *targetClient, Channel *targetChannel) const;

	private:
		INVITE(void);
		INVITE(INVITE const &copy);
};

#endif
