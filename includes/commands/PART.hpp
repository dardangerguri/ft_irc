#ifndef PART_HPP
# define PART_HPP

# include "ACommand.hpp"

class PART : public ACommand {
	public:
		PART(Commands *c);
		~PART(void);

		PART &operator=(PART const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(Channel *channel, std::string reason);

	private:
		PART(void);
		PART(PART const &copy);

		std::vector<std::string>	parseMessage(std::string message, Client *source);
};

#endif
