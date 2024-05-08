#ifndef ERR_NOTONCHANNEL_HPP
# define ERR_NOTONCHANNEL_HPP

# include "ACommand.hpp"

class ERR_NOTONCHANNEL : public ACommand {
	public:
		ERR_NOTONCHANNEL(void);
		~ERR_NOTONCHANNEL(void);

		ERR_NOTONCHANNEL &operator=(ERR_NOTONCHANNEL const &copy);

		std::string const	arranger(Client *source, Channel *channel) const;

	private:
		ERR_NOTONCHANNEL(ERR_NOTONCHANNEL const &copy);
};

#endif
