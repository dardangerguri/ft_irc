#ifndef ERR_ALREADYREGISTERED_HPP
# define ERR_ALREADYREGISTERED_HPP

# include "ACommand.hpp"

class ERR_ALREADYREGISTERED : public ACommand {
	public:
		ERR_ALREADYREGISTERED(void);
		~ERR_ALREADYREGISTERED(void);

		ERR_ALREADYREGISTERED &operator=(ERR_ALREADYREGISTERED const &copy);

		std::string	arranger(Client *source) const;

	private:
		ERR_ALREADYREGISTERED(ERR_ALREADYREGISTERED const &copy);
};

#endif
