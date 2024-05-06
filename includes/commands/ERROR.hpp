#ifndef ERROR_HPP
# define ERROR_HPP

# include "ACommand.hpp"

class ERROR : public ACommand {
	public:
		ERROR(Commands *c);
		~ERROR(void);

		ERROR &operator=(ERROR const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(std::string message);

	private:
		ERROR(void);
		ERROR(NICK const &copy);
};

#endif
