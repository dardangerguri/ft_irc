#ifndef ERR_USERSDONTMATCH_HPP
# define ERR_USERSDONTMATCH_HPP

# include "ACommand.hpp"

class ERR_USERSDONTMATCH : public ACommand {
	public:
		ERR_USERSDONTMATCH(void);
		~ERR_USERSDONTMATCH(void);

		ERR_USERSDONTMATCH &operator=(ERR_USERSDONTMATCH const &copy);

		std::string const	arranger(Client *source) const;

	private:
		ERR_USERSDONTMATCH(ERR_USERSDONTMATCH const &copy);
};

#endif
