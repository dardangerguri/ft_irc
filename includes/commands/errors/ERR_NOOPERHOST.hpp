#ifndef ERR_NOOPERHOST_HPP
# define ERR_NOOPERHOST_HPP

# include "ACommand.hpp"

class ERR_NOOPERHOST : public ACommand {
	public:
		ERR_NOOPERHOST(void);
		~ERR_NOOPERHOST(void);

		ERR_NOOPERHOST &operator=(ERR_NOOPERHOST const &copy);

		std::string const	arranger(Client *source) const;

	private:
		ERR_NOOPERHOST(ERR_NOOPERHOST const &copy);
};

#endif
