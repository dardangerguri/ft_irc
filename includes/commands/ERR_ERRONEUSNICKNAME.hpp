#ifndef ERR_ERRONEUSNICKNAME_HPP
# define ERR_ERRONEUSNICKNAME_HPP

# include "ACommand.hpp"

class ERR_ERRONEUSNICKNAME : public ACommand {
	public:
		ERR_ERRONEUSNICKNAME(void);
		~ERR_ERRONEUSNICKNAME(void);

		ERR_ERRONEUSNICKNAME &operator=(ERR_ERRONEUSNICKNAME const &copy);

		std::string	arranger(std::string sourceNickname, Client *client);

	private:
		ERR_ERRONEUSNICKNAME(ERR_ERRONEUSNICKNAME const &copy);
};

#endif
