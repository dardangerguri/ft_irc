#ifndef ERR_NOSUCHCHANNEL_HPP
# define ERR_NOSUCHCHANNEL_HPP

# include "ACommand.hpp"

class ERR_NOSUCHCHANNEL : public ACommand {
	public:
		ERR_NOSUCHCHANNEL(void);
		~ERR_NOSUCHCHANNEL(void);

		ERR_NOSUCHCHANNEL &operator=(ERR_NOSUCHCHANNEL const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		ERR_NOSUCHCHANNEL(ERR_NOSUCHCHANNEL const &copy);
};

#endif
