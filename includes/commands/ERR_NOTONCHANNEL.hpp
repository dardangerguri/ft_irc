#ifndef ERR_NOTONCHANNEL_HPP
# define ERR_NOTONCHANNEL_HPP

# include "ACommand.hpp"

class ERR_NOTONCHANNEL : public ACommand {
	public:
		ERR_NOTONCHANNEL(void);
		~ERR_NOTONCHANNEL(void);

		ERR_NOTONCHANNEL &operator=(ERR_NOTONCHANNEL const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		ERR_NOTONCHANNEL(ERR_NOTONCHANNEL const &copy);
};

#endif
