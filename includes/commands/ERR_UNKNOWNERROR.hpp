#ifndef ERR_UNKNOWNERROR_HPP
# define ERR_UNKNOWNERROR_HPP

# include "ACommand.hpp"

class ERR_UNKNOWNERROR : public ACommand {
	public:
		ERR_UNKNOWNERROR(void);
		~ERR_UNKNOWNERROR(void);

		ERR_UNKNOWNERROR &operator=(ERR_UNKNOWNERROR const &copy);

		std::string	arranger(std::string sourceCommand, std::string info, Client *source);

	private:
		ERR_UNKNOWNERROR(ERR_UNKNOWNERROR const &copy);
};

#endif
