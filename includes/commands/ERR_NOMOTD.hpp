#ifndef ERR_NOMOTD_HPP
# define ERR_NOMOTD_HPP

# include "ACommand.hpp"

class ERR_NOMOTD : public ACommand {
	public:
		ERR_NOMOTD(void);
		~ERR_NOMOTD(void);

		ERR_NOMOTD &operator=(ERR_NOMOTD const &copy);

		std::string	arranger(Client *source);

	private:
		ERR_NOMOTD(ERR_NOMOTD const &copy);
};

#endif
