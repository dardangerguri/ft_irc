#ifndef TOPIC_HPP
# define TOPIC_HPP

# include "ACommand.hpp"
# include <chrono>

class TOPIC : public ACommand {
	public:
		TOPIC(Commands *c);
		~TOPIC(void);

		TOPIC &operator=(TOPIC const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(Channel *channel, std::string const topic) const;

	private:
		TOPIC(void);
		TOPIC(TOPIC const &copy);

		std::vector<std::string>	parseMessage(std::string const message) const;
		std::time_t					getCurrTime(void) const;
};

#endif
