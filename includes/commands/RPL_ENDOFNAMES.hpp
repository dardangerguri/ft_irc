#ifndef RPL_ENDOFNAMES_HPP
# define RPL_ENDOFNAMES_HPP

# include "ACommand.hpp"

class RPL_ENDOFNAMES : public ACommand {
	public:
		RPL_ENDOFNAMES(void);
		~RPL_ENDOFNAMES(void);

		RPL_ENDOFNAMES &operator=(RPL_ENDOFNAMES const &copy);

		std::string	arranger(Client *source, Channel *channel) const;
		std::string	arranger(Client *source, std::string const channelName) const;

	private:
		RPL_ENDOFNAMES(RPL_ENDOFNAMES const &copy);
};

#endif
