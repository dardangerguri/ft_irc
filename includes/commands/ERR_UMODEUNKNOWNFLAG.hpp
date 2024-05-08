#ifndef ERR_UMODEUNKNOWNFLAG_HPP
# define ERR_UMODEUNKNOWNFLAG_HPP

# include "ACommand.hpp"

class ERR_UMODEUNKNOWNFLAG : public ACommand {
	public:
		ERR_UMODEUNKNOWNFLAG(void);
		~ERR_UMODEUNKNOWNFLAG(void);

		ERR_UMODEUNKNOWNFLAG &operator=(ERR_UMODEUNKNOWNFLAG const &copy);

		std::string	arranger(Client *source) const;

	private:
		ERR_UMODEUNKNOWNFLAG(ERR_UMODEUNKNOWNFLAG const &copy);
};

#endif
