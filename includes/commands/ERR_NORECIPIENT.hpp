#ifndef ERR_NORECIPIENT_HPP
# define ERR_NORECIPIENT_HPP

# include "ACommand.hpp"

class ERR_NORECIPIENT : public ACommand {
	public:
		ERR_NORECIPIENT(void);
		~ERR_NORECIPIENT(void);

		ERR_NORECIPIENT &operator=(ERR_NORECIPIENT const &copy);

		std::string const	arranger(std::string const sourceCommand, Client *source) const;

	private:
		ERR_NORECIPIENT(ERR_NORECIPIENT const &copy);
};

#endif
