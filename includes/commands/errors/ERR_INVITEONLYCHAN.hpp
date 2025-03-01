#ifndef ERR_INVITEONLYCHAN_HPP
# define ERR_INVITEONLYCHAN_HPP

# include "ACommand.hpp"

class ERR_INVITEONLYCHAN : public ACommand {
	public:
		ERR_INVITEONLYCHAN(void);
		~ERR_INVITEONLYCHAN(void);

		ERR_INVITEONLYCHAN &operator=(ERR_INVITEONLYCHAN const &copy);

		std::string const	arranger(Client *source, Channel *channel) const;

	private:
		ERR_INVITEONLYCHAN(ERR_INVITEONLYCHAN const &copy);
};

#endif
