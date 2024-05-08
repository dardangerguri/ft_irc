#ifndef USER_HPP
# define USER_HPP

# include "ACommand.hpp"

class USER : public ACommand {
	public:
		USER(Commands *c);
		~USER(void);

		USER &operator=(USER const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(void) const;

	private:
		USER(void);
		USER(USER const &copy);

		bool						validateParameters(std::vector<std::string> & parameters) const;
		std::vector<std::string>	parseMessage(std::string const message) const;
};

#endif
