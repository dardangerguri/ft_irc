#ifndef PING_HPP
# define PING_HPP

# include "ACommand.hpp"

class PING : public ACommand {
	public:
		PING(Commands *c);
		~PING(void);

		PING &operator=(PING const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(void) const;

	private:
		PING(void);
		PING(PING const &copy);
};

#endif
