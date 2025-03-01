#ifndef NAMES_HPP
# define NAMES_HPP

# include "ACommand.hpp"

class NAMES : public ACommand {
	public:
		NAMES(Commands *c);
		~NAMES(void);

		NAMES &operator=(NAMES const &copy);

		void				handleCommand(std::string const message, Client *source);
		std::string const	arranger(Channel *targetChannel) const;

	private:
		NAMES(void);
		NAMES(NAMES const &copy);
};

#endif
