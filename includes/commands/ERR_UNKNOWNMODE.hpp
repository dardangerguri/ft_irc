#ifndef ERR_UNKNOWNMODE_HPP
# define ERR_UNKNOWNMODE_HPP

# include "ACommand.hpp"

class ERR_UNKNOWNMODE : public ACommand {
	public:
		ERR_UNKNOWNMODE(void);
		~ERR_UNKNOWNMODE(void);

		ERR_UNKNOWNMODE &operator=(ERR_UNKNOWNMODE const &copy);

		std::string	arranger(char const mode, Client *source) const;

	private:
		ERR_UNKNOWNMODE(ERR_UNKNOWNMODE const &copy);
};

#endif
