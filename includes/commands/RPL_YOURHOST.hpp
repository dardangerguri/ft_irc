#ifndef RPL_YOURHOST_HPP
# define RPL_YOURHOST_HPP

# include "ACommand.hpp"

class RPL_YOURHOST : public ACommand {
	public:
		RPL_YOURHOST(void);
		~RPL_YOURHOST(void);

		RPL_YOURHOST &operator=(RPL_YOURHOST const &copy);

		std::string const	arranger(Client *source) const;

	private:
		RPL_YOURHOST(RPL_YOURHOST const &copy);
};

#endif
