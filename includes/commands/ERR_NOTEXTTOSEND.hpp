#ifndef ERR_NOTEXTTOSEND_HPP
# define ERR_NOTEXTTOSEND_HPP

# include "ACommand.hpp"

class ERR_NOTEXTTOSEND : public ACommand {
	public:
		ERR_NOTEXTTOSEND(void);
		~ERR_NOTEXTTOSEND(void);

		ERR_NOTEXTTOSEND &operator=(ERR_NOTEXTTOSEND const &copy);

		std::string	arranger(Client *source);

	private:
		ERR_NOTEXTTOSEND(ERR_NOTEXTTOSEND const &copy);
};

#endif