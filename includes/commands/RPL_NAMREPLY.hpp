#ifndef RPL_NAMREPLY_HPP
# define RPL_NAMREPLY_HPP

# include "ACommand.hpp"

class RPL_NAMREPLY : public ACommand {
	public:
		RPL_NAMREPLY(void);
		~RPL_NAMREPLY(void);

		RPL_NAMREPLY &operator=(RPL_NAMREPLY const &copy);

		std::string	arranger(Client *source, Channel *channel, Client *user);

	private:
		RPL_NAMREPLY(RPL_NAMREPLY const &copy);
};

#endif
