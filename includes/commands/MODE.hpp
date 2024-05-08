#ifndef MODE_HPP
# define MODE_HPP

# include "ACommand.hpp"

class MODE : public ACommand {
	public:
		MODE(Commands *c);
		~MODE(void);

		MODE &operator=(MODE const &copy);

		void		handleCommand(std::string const message, Client *source);
		std::string	arranger(std::string const message, Channel *targetChannel) const;
		std::string	arranger(std::string const message, Client *targetClient) const;

	private:
		MODE(void);
		MODE(MODE const &copy);

		void		handleClientModes(std::vector<std::string> const parameters, Client *source, Client *targetClient);
		void		handleChannelModes(std::vector<std::string> const parameters, Client *source, Channel *targetChannel);
		bool		handleChannelOperatorMode(std::string const parameter, bool const setFlag, Client *source, Channel *targetChannel);
		bool		handleKeyMode(std::string const parameter, bool const setFlag, bool const keyFlag, Channel *targetChannel);
		bool		handleClientLimitMode(std::string const parameter, bool const setFlag, bool const clientLimitFlag, Channel *targetChannel);
		void		handleInviteOnlyMode(bool const setFlag, Channel *targetChannel);
		void		handleTopicMode(bool const setFlag, Channel *targetChannel);
		std::string	parseModeMessage(std::string modeString, std::vector<std::string> const modeParameters);
};

#endif
