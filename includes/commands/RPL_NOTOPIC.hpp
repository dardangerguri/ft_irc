#ifndef RPL_NOTOPIC_HPP
# define RPL_NOTOPIC_HPP

# include "ACommand.hpp"

class RPL_NOTOPIC : public ACommand {
	public:
		RPL_NOTOPIC(void);
		~RPL_NOTOPIC(void);

		RPL_NOTOPIC &operator=(RPL_NOTOPIC const &copy);

		std::string	arranger(Client *source, Channel *channel);

	private:
		RPL_NOTOPIC(RPL_NOTOPIC const &copy);
};

#endif