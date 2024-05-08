#ifndef RPL_WELCOME_HPP
# define RPL_WELCOME_HPP

# include "ACommand.hpp"

class RPL_WELCOME : public ACommand {
	public:
		RPL_WELCOME(void);
		~RPL_WELCOME(void);

		RPL_WELCOME &operator=(RPL_WELCOME const &copy);

		std::string	arranger(Client *source) const;

	private:
		RPL_WELCOME(RPL_WELCOME const &copy);
};

#endif
