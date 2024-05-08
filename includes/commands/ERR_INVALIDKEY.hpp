#ifndef ERR_INVALIDKEY_HPP
# define ERR_INVALIDKEY_HPP

# include "ACommand.hpp"

class ERR_INVALIDKEY : public ACommand {
	public:
		ERR_INVALIDKEY(void);
		~ERR_INVALIDKEY(void);

		ERR_INVALIDKEY &operator=(ERR_INVALIDKEY const &copy);

		std::string	arranger(Client *source, Channel *channel) const;

	private:
		ERR_INVALIDKEY(ERR_INVALIDKEY const &copy);
};

#endif
