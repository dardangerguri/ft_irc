#ifndef MOTD_HPP
# define MOTD_HPP

# include "ACommand.hpp"
# include <random>
# include <vector>

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

		std::vector<std::string> const	getRandomMotd(void) const;
};

#endif
