#ifndef ERR_NONICKNAMEGIVEN_HPP
# define ERR_NONICKNAMEGIVEN_HPP

# include "ACommand.hpp"

class ERR_NONICKNAMEGIVEN : public ACommand {
	public:
		ERR_NONICKNAMEGIVEN(void);
		~ERR_NONICKNAMEGIVEN(void);

		ERR_NONICKNAMEGIVEN &operator=(ERR_NONICKNAMEGIVEN const &copy);

		std::string const	arranger(Client *source) const;

	private:
		ERR_NONICKNAMEGIVEN(ERR_NONICKNAMEGIVEN const &copy);
};

#endif
