#ifndef ERR_UNKNOWNCOMMAND_HPP
# define ERR_UNKNOWNCOMMAND_HPP

# include "ACommand.hpp"

class ERR_UNKNOWNCOMMAND : public ACommand {
	public:
		ERR_UNKNOWNCOMMAND(void);
		~ERR_UNKNOWNCOMMAND(void);

		ERR_UNKNOWNCOMMAND &operator=(ERR_UNKNOWNCOMMAND const &copy);

		std::string const	arranger(std::string const sourceCommand, Client *source) const;

	private:
		ERR_UNKNOWNCOMMAND(ERR_UNKNOWNCOMMAND const &copy);
};

#endif
