#ifndef MODE_HPP
# define MODE_HPP

# include "ACommand.hpp"

class MODE : public ACommand {
	public:
		MODE(Commands *c);
		~MODE(void);

		MODE &operator=(MODE const &copy);

		void		handleCommand(std::string message, Client *source);
		std::string	arranger(std::string message, Channel *targetChannel);
		std::string	arranger(std::string message, Client *targetClient);

	private:
		MODE(void);
		MODE(MODE const &copy);

		void		handleChannelModes(std::vector<std::string> parameters, Client *source, Channel *targetChannel);
		void		handleClientModes(std::vector<std::string> parameters, Client *source, Client *targetClient);
		bool		handleChannelOperatorMode(std::string parameter, bool setFlag, Client *source, Channel *targetChannel);
		bool		handleKeyMode(std::string parameter, bool setFlag, bool &keyFlag, Channel *targetChannel);
		bool		handleClientLimitMode(std::string parameter, bool setFlag, bool &clientLimitFlag, Channel *targetChannel);
		void		handleInviteOnlyMode(bool setFlag, Channel *targetChannel);
		void		handleTopicMode(bool setFlag, Channel *targetChannel);
		std::string	parseModeMessage(std::string modeString, std::vector<std::string> modeParameters);
};

#endif
