#ifndef RPL_MOTDSTART_HPP
# define RPL_MOTDSTART_HPP

# include "ACommand.hpp"

class RPL_MOTDSTART : public ACommand {
	public:
		RPL_MOTDSTART(void);
		~RPL_MOTDSTART(void);

		RPL_MOTDSTART &operator=(RPL_MOTDSTART const &copy);

		std::string const	arranger(Client *source) const;

	private:
		RPL_MOTDSTART(RPL_MOTDSTART const &copy);
};

#endif
