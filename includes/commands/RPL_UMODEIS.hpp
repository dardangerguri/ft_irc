#ifndef RPL_UMODEIS_HPP
# define RPL_UMODEIS_HPP

# include "ACommand.hpp"

class RPL_UMODEIS : public ACommand {
	public:
		RPL_UMODEIS(void);
		~RPL_UMODEIS(void);

		RPL_UMODEIS &operator=(RPL_UMODEIS const &copy);

		std::string const	arranger(Client *source) const;

	private:
		RPL_UMODEIS(RPL_UMODEIS const &copy);
};

#endif
