#ifndef BOT_HPP
# define BOT_HPP

# include "Client.hpp"
# include "Commands.hpp"
# include <vector>
# include <random>

class Bot : public Client {
	public:
		Bot(Commands *c);
		~Bot(void);

		void handleBotMessage(std::string const message, Channel *target);
		void handleBotMessage(std::string const message, Client *target);

	private:
		Bot(void);
		Bot(Bot const &copy);
		Bot &operator=(Bot const &copy);

		Commands	*commands;

		std::string const	getJoke(void) const;
};

#endif
