#ifndef ERR_NICKNAMEINUSE_HPP
# define ERR_NICKNAMEINUSE_HPP

# include "ACommand.hpp"

class ERR_NICKNAMEINUSE : public ACommand {
	public:
		ERR_NICKNAMEINUSE(void);
		~ERR_NICKNAMEINUSE(void);

		ERR_NICKNAMEINUSE &operator=(ERR_NICKNAMEINUSE const &copy);

		std::string	arranger(std::string nicknameInUse, Client *source);

	private:
		ERR_NICKNAMEINUSE(ERR_NICKNAMEINUSE const &copy);
};

#endif
