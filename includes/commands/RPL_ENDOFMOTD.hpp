#ifndef RPL_ENDOFMOTD_HPP
# define RPL_ENDOFMOTD_HPP

# include "ACommand.hpp"

class RPL_ENDOFMOTD : public ACommand {
	public:
		RPL_ENDOFMOTD(void);
		~RPL_ENDOFMOTD(void);

		RPL_ENDOFMOTD &operator=(RPL_ENDOFMOTD const &copy);

		std::string	arranger(Client *source) const;

	private:
		RPL_ENDOFMOTD(RPL_ENDOFMOTD const &copy);
};

#endif
