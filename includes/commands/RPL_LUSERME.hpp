#ifndef RPL_LUSERME_HPP
# define RPL_LUSERME_HPP

# include "ACommand.hpp"

class RPL_LUSERME : public ACommand {
	public:
		RPL_LUSERME(Commands *c);
		~RPL_LUSERME(void);

		RPL_LUSERME &operator=(RPL_LUSERME const &copy);

		std::string	arranger(Client *source) const;

	private:
		RPL_LUSERME(void);
		RPL_LUSERME(RPL_LUSERME const &copy);
};

#endif
