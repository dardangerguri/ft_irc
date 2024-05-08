#ifndef RPL_MOTD_HPP
# define RPL_MOTD_HPP

# include "ACommand.hpp"

class RPL_MOTD : public ACommand {
	public:
		RPL_MOTD(void);
		~RPL_MOTD(void);

		RPL_MOTD &operator=(RPL_MOTD const &copy);

		std::string const	arranger(Client *source, std::string const motdLine) const;

	private:
		RPL_MOTD(RPL_MOTD const &copy);
};

#endif
