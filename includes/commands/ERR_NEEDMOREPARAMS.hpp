#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

# include "ACommand.hpp"

class ERR_NEEDMOREPARAMS : public ACommand {
	public:
		ERR_NEEDMOREPARAMS(void);
		~ERR_NEEDMOREPARAMS(void);

		ERR_NEEDMOREPARAMS &operator=(ERR_NEEDMOREPARAMS const &copy);

		std::string	arranger(std::string sourceCommand, Client *client);

	private:
		ERR_NEEDMOREPARAMS(ERR_NEEDMOREPARAMS const &copy);
};

#endif
