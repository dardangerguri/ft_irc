#ifndef ERR_NEEDMOREPARAMS_HPP
# define ERR_NEEDMOREPARAMS_HPP

# include "ACommand.hpp"

class ERR_NEEDMOREPARAMS : public ACommand {
	public:
		ERR_NEEDMOREPARAMS(void);
		~ERR_NEEDMOREPARAMS(void);

		ERR_NEEDMOREPARAMS &operator=(ERR_NEEDMOREPARAMS const &copy);

		std::string const	arranger(std::string sourceCommand, Client *source) const;

	private:
		ERR_NEEDMOREPARAMS(ERR_NEEDMOREPARAMS const &copy);
};

#endif
