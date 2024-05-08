#include "Channel.hpp"

Channel::Channel(std::string const name) : name(name) {
}

Channel::~Channel() {
}

std::string Channel::getName() const {
	return (name);
}

std::string Channel::getTopic() const {
	return (topic);
}

std::string Channel::getTopicAuthor(void) const {
	return (topicAuthor);
}

std::time_t Channel::getTopicTime(void) const {
	return (topicTime);
}

unsigned int Channel::getUserLimit() const {
	return (userLimit);
}

unsigned int Channel::getUserCount() const {
	return (users.size());
}

std::unordered_set<Client *> Channel::getUserList() const {
	return (users);
}

std::string Channel::getPassword() const {
	return (password);
}

void Channel::setTopic(std::string const newTopic) {
	topic = newTopic;
}

void Channel::setTopicAuthor(Client *user) {
	if (user)
		topicAuthor = user->getNickname();
}

void Channel::setTopicTime(std::time_t const time) {
	topicTime = time;
}

void Channel::setUserLimit(unsigned int const newLimit) {
	userLimit = newLimit;
}

void Channel::setPassword(std::string const newPassword) {
	password = newPassword;
}

bool Channel::checkPassword(std::string const input) const {
	// FIXME if client provides invalid password send back ERR_BADCHANNELKEY
	if (input == password)
		return (true);
	return (false);
}

bool Channel::validatePassword(std::string const password) const {
	// FIXME if validation fails, send ERR_INVALIDMODEPARAM or ERR_INVALIDKEY to client
	if (password.empty())
		return (false);
	if (std::string(password).find(' ') != std::string::npos)
		return (false);
	return (true);
}

bool Channel::isAllowedChannelMode(char const mode) const {
	// Channel modes supported by this server:
	// i : Set/remove Invite-only channel
	// t : Set/remove the restrictions of the TOPIC command to channel operators
	// k : Set/remove the channel key (password)
	// o : Give/take channel operator privilege
	// l : Set/remove the user limit to channel

	// FIXME This function checks channel modes that we can accept as parameter
	// to MODE. However things are way more complicated than that:
	// - setting or unsetting 'k' and 'o' mode always requires parameter
	// - 'l' requires parameter only when set (+l) but must not have one when unset (-l)
	// - 'i' and 't' must not have parameter in any case
	// - 'o' mode is not added to the channel modes list. It gives channel operator
	//   privileges to a user by adding the client to 'operators' container
	//
	// Channel class should have methods for handling anything related to these

	std::unordered_set<char> supportedModes = {'i', 't', 'k', 'o', 'l'};

	if (supportedModes.find(mode) != supportedModes.end())
		return (true);
	return (false);
}

bool Channel::addMode(char const mode) {
	if (!isAllowedChannelMode(mode))
		return (false);
	try {
		channelMode.insert(mode);
		return (true);
	}
	catch (...) {
		return (false);
	}
}

bool Channel::delMode(char const mode) {
	if (!isAllowedChannelMode(mode))
		return (false);
	channelMode.erase(mode);
	return (true);
}

bool Channel::hasMode(char const mode) const {
	if (channelMode.find(mode) != channelMode.end())
		return (true);
	return (false);
}

bool Channel::userJoin(Client *user) {
	if (!user)
		return (false);
	try {
		users.insert(user);
	}
	catch (...) {
		return (false);
	}
	if (!user->inChannel(this)) {
		if (!user->joinChannel(this)) {
			users.erase(user);
			return (false);
		}
	}
	if (users.size() == 1 && operators.empty())
		userMakeOperator(user);
	return (true);
}

void Channel::userLeave(Client *user) {
	if (user) {
		users.erase(user);
		userRemoveOperator(user);
		if (user->inChannel(this))
			user->leaveChannel(this);
	}
}

bool Channel::userIsJoined(Client *user) const {
	if (user && users.find(user) != users.end())
		return (true);
	return (false);
}

bool Channel::userIsOperator(Client *user) const {
	if (user && operators.find(user) != operators.end())
		return (true);
	return (false);
}

bool Channel::userMakeOperator(Client *user) {
	if (!user)
		return (false);
	try {
		operators.insert(user);
	}
	catch (...) {
		return (false);
	}
	return (true);
}

void Channel::userRemoveOperator(Client *user) {
	if (user)
		operators.erase(user);
}
