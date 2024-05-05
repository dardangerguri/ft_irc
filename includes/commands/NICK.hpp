#ifndef NICK_HPP
# define NICK_HPP

# include "ACommand.hpp"

class NICK : public ACommand {
	public:
		NICK(Commands *c);
		~NICK(void);

		NICK &operator=(NICK const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(std::string newNickname);

	private:
		NICK(void);
		NICK(NICK const &copy);

		bool	validateNickname(std::string &input);
};

#endif
