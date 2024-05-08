#ifndef RPL_TOPIC_HPP
# define RPL_TOPIC_HPP

# include "ACommand.hpp"

class RPL_TOPIC : public ACommand {
	public:
		RPL_TOPIC(void);
		~RPL_TOPIC(void);

		RPL_TOPIC &operator=(RPL_TOPIC const &copy);

		std::string	arranger(Client *source, Channel *channel) const;

	private:
		RPL_TOPIC(RPL_TOPIC const &copy);
};

#endif
