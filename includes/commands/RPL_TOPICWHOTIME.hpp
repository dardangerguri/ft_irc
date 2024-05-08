#ifndef RPL_TOPICWHOTIME_HPP
# define RPL_TOPICWHOTIME_HPP

# include "ACommand.hpp"

class RPL_TOPICWHOTIME : public ACommand {
	public:
		RPL_TOPICWHOTIME(void);
		~RPL_TOPICWHOTIME(void);

		RPL_TOPICWHOTIME &operator=(RPL_TOPICWHOTIME const &copy);

		std::string const	arranger(Client *source, Channel *channel) const;

	private:
		RPL_TOPICWHOTIME(RPL_TOPICWHOTIME const &copy);
};

#endif
