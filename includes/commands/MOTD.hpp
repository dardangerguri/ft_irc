#ifndef MOTD_HPP
# define MOTD_HPP

# include "ACommand.hpp"

class MOTD : public ACommand {
	public:
		MOTD(Commands *c);
		~MOTD(void);

		MOTD &operator=(MOTD const &copy);

		void				handleCommand(std::string const message, Client *source);
		std::string const	arranger() const;

	private:
		MOTD(void);
		MOTD(MOTD const &copy);
};

#endif
