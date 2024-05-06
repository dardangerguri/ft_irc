#ifndef RPL_CHANNELMODEIS_HPP
# define RPL_CHANNELMODEIS_HPP

# include "ACommand.hpp"

class RPL_CHANNELMODEIS : public ACommand {
	public:
		RPL_CHANNELMODEIS(void);
		~RPL_CHANNELMODEIS(void);

		RPL_CHANNELMODEIS &operator=(RPL_CHANNELMODEIS const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		RPL_CHANNELMODEIS(RPL_CHANNELMODEIS const &copy);
};

#endif
