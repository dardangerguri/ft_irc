#ifndef RPL_LUSERCLIENT_HPP
# define RPL_LUSERCLIENT_HPP

# include "ACommand.hpp"

class RPL_LUSERCLIENT : public ACommand {
	public:
		RPL_LUSERCLIENT(Commands *c);
		~RPL_LUSERCLIENT(void);

		RPL_LUSERCLIENT &operator=(RPL_LUSERCLIENT const &copy);

		std::string	arranger(Client *source);

	private:
		RPL_LUSERCLIENT(void);
		RPL_LUSERCLIENT(RPL_LUSERCLIENT const &copy);
};

#endif
