#ifndef USER_HPP
# define USER_HPP

# include "ACommand.hpp"

class USER : public ACommand {
	public:
		USER(Commands *c);
		~USER(void);

		USER &operator=(USER const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(void);

	private:
		USER(void);
		USER(USER const &copy);

		bool						validateParameters(std::vector<std::string> & parameters);
		std::vector<std::string>	parseMessage(std::string message);
};

#endif
