#ifndef ERR_PASSWDMISMATCH_HPP
# define ERR_PASSWDMISMATCH_HPP

# include "ACommand.hpp"

class ERR_PASSWDMISMATCH : public ACommand {
	public:
		ERR_PASSWDMISMATCH(void);
		~ERR_PASSWDMISMATCH(void);

		ERR_PASSWDMISMATCH &operator=(ERR_PASSWDMISMATCH const &copy);

		std::string const	arranger(Client *source) const;

	private:
		ERR_PASSWDMISMATCH(ERR_PASSWDMISMATCH const &copy);
};

#endif
