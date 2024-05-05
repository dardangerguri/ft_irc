#ifndef ERR_BADCHANNELKEY_HPP
# define ERR_BADCHANNELKEY_HPP

# include "ACommand.hpp"

class ERR_BADCHANNELKEY : public ACommand {
	public:
		ERR_BADCHANNELKEY(void);
		~ERR_BADCHANNELKEY(void);

		ERR_BADCHANNELKEY &operator=(ERR_BADCHANNELKEY const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		ERR_BADCHANNELKEY(ERR_BADCHANNELKEY const &copy);
};

#endif