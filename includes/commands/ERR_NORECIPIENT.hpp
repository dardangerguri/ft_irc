#ifndef ERR_NORECIPIENT_HPP
# define ERR_NORECIPIENT_HPP

# include "ACommand.hpp"

class ERR_NORECIPIENT : public ACommand {
	public:
		ERR_NORECIPIENT(void);
		~ERR_NORECIPIENT(void);

		ERR_NORECIPIENT &operator=(ERR_NORECIPIENT const &copy);

		std::string	arranger(std::string sourceCommand, Client *source);

	private:
		ERR_NORECIPIENT(ERR_NORECIPIENT const &copy);
};

#endif
