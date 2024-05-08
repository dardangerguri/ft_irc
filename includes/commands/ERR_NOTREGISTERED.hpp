#ifndef ERR_NOTREGISTERED_HPP
# define ERR_NOTREGISTERED_HPP

# include "ACommand.hpp"

class ERR_NOTREGISTERED : public ACommand {
	public:
		ERR_NOTREGISTERED(void);
		~ERR_NOTREGISTERED(void);

		ERR_NOTREGISTERED &operator=(ERR_NOTREGISTERED const &copy);

		std::string const	arranger(Client *source) const;

	private:
		ERR_NOTREGISTERED(ERR_NOTREGISTERED const &copy);
};

#endif
