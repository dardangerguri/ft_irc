#ifndef PONG_HPP
# define PONG_HPP

# include "ACommand.hpp"

class PONG : public ACommand {
	public:
		PONG(Commands *c);
		~PONG(void);

		PONG &operator=(PONG const &copy);

		void				handleCommand(std::string const message, Client *source);
		std::string const	arranger(std::vector<std::string> const parameters) const;

	private:
		PONG(void);
		PONG(PONG const &copy);
};

#endif
