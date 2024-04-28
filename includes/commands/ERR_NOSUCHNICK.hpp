#ifndef ERR_NOSUCHNICK_HPP
# define ERR_NOSUCHNICK_HPP

# include "ACommand.hpp"

class ERR_NOSUCHNICK : public ACommand {
	public:
		ERR_NOSUCHNICK(void);
		~ERR_NOSUCHNICK(void);

		ERR_NOSUCHNICK &operator=(ERR_NOSUCHNICK const &copy);

		std::string	arranger(std::string sourceNickname, Client *source);

	private:
		ERR_NOSUCHNICK(ERR_NOSUCHNICK const &copy);
};

#endif
