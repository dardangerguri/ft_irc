#ifndef OPER_HPP
# define OPER_HPP

# include "ACommand.hpp"

class OPER : public ACommand {
	public:
		OPER(Commands *c);
		~OPER(void);

		OPER &operator=(OPER const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(void) const;

	private:
		OPER(void);
		OPER(OPER const &copy);

		const std::string	operName = "oper";
		const std::string	operPasswd = "oper";
		const char			*validHost = "127.0.0.1";
};

#endif
