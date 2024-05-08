#ifndef RPL_CREATED_HPP
# define RPL_CREATED_HPP

# include "ACommand.hpp"

class RPL_CREATED : public ACommand {
	public:
		RPL_CREATED(void);
		~RPL_CREATED(void);

		RPL_CREATED &operator=(RPL_CREATED const &copy);

		std::string	arranger(Client *source) const;

	private:
		RPL_CREATED(RPL_CREATED const &copy);
};

#endif
