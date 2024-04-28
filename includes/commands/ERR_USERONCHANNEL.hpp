#ifndef ERR_USERONCHANNEL_HPP
# define ERR_USERONCHANNEL_HPP

# include "ACommand.hpp"

class ERR_USERONCHANNEL : public ACommand {
	public:
		ERR_USERONCHANNEL(void);
		~ERR_USERONCHANNEL(void);

		ERR_USERONCHANNEL &operator=(ERR_USERONCHANNEL const &copy);

		std::string	arranger(Client *source, Client *target, Channel *channel);

	private:
		ERR_USERONCHANNEL(ERR_USERONCHANNEL const &copy);
};

#endif
