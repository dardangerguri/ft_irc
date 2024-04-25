#ifndef PONG_HPP
# define PONG_HPP

# include "ACommand.hpp"

class PONG : public ACommand {
	public:
		PONG(Commands *c);
		~PONG(void);

		PONG &operator=(PONG const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(std::vector<std::string> parameters);

	private:
		PONG(void);
		PONG(PONG const &copy);
};

#endif
