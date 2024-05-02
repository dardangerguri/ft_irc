#ifndef JOIN_HPP
# define JOIN_HPP

# include "ACommand.hpp"

class JOIN : public ACommand {
	public:
		JOIN(Commands *c);
		~JOIN(void);

		JOIN &operator=(JOIN const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(Channel *channel);

	private:
		JOIN(void);
		JOIN(JOIN const &copy);
};

#endif
