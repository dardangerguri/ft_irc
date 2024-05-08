#ifndef MOTD_HPP
# define MOTD_HPP

# include "ACommand.hpp"
# include <fstream>

class MOTD : public ACommand {
	public:
		MOTD(Commands *c);
		~MOTD(void);

		MOTD &operator=(MOTD const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger() const;

	private:
		MOTD(void);
		MOTD(MOTD const &copy);
};

#endif
