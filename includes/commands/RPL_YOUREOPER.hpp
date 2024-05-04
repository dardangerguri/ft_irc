#ifndef RPL_YOUREOPER_HPP
# define RPL_YOUREOPER_HPP

# include "ACommand.hpp"

class RPL_YOUREOPER : public ACommand {
	public:
		RPL_YOUREOPER(void);
		~RPL_YOUREOPER(void);

		RPL_YOUREOPER &operator=(RPL_YOUREOPER const &copy);

		std::string	arranger(Client *source);

	private:
		RPL_YOUREOPER(RPL_YOUREOPER const &copy);
};

#endif
