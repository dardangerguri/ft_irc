#ifndef ERR_USERNOTINCHANNEL_HPP
# define ERR_USERNOTINCHANNEL_HPP

# include "ACommand.hpp"

class ERR_USERNOTINCHANNEL : public ACommand {
	public:
		ERR_USERNOTINCHANNEL(void);
		~ERR_USERNOTINCHANNEL(void);

		ERR_USERNOTINCHANNEL &operator=(ERR_USERNOTINCHANNEL const &copy);

		std::string const	arranger(std::string const nickname, Client *source, Channel *channel) const;

	private:
		ERR_USERNOTINCHANNEL(ERR_USERNOTINCHANNEL const &copy);
};

#endif
