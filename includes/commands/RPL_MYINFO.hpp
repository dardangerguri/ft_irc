#ifndef RPL_MYINFO_HPP
# define RPL_MYINFO_HPP

# include "ACommand.hpp"

class RPL_MYINFO : public ACommand {
	public:
		RPL_MYINFO(void);
		~RPL_MYINFO(void);

		RPL_MYINFO &operator=(RPL_MYINFO const &copy);

		std::string const	arranger(Client *source) const;

	private:
		RPL_MYINFO(RPL_MYINFO const &copy);
};

#endif
