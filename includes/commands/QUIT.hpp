#ifndef QUIT_HPP
# define QUIT_HPP

# include "ACommand.hpp"

class QUIT : public ACommand {
	public:
		QUIT(Commands *c);
		~QUIT(void);

		QUIT &operator=(QUIT const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(std::string message);

	private:
		QUIT(void);
		QUIT(NICK const &copy);
};

#endif
