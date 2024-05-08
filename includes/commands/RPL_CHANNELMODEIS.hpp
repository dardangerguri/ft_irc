#ifndef RPL_CHANNELMODEIS_HPP
# define RPL_CHANNELMODEIS_HPP

# include "ACommand.hpp"

class RPL_CHANNELMODEIS : public ACommand {
	public:
		RPL_CHANNELMODEIS(void);
		~RPL_CHANNELMODEIS(void);

		RPL_CHANNELMODEIS &operator=(RPL_CHANNELMODEIS const &copy);

		std::string const	arranger(Client *source, Channel *channel) const;

	private:
		RPL_CHANNELMODEIS(RPL_CHANNELMODEIS const &copy);
};

#endif
