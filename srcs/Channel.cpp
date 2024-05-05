#include "Channel.hpp"

Channel::Channel(std::string name) : name(name) {
}

Channel::~Channel() {
}

std::string Channel::getName() {
	return (name);
}

std::string Channel::getTopic() {
	return (topic);
}

std::string Channel::getTopicAuthor(void) {
	return (topicAuthor);
}

std::time_t Channel::getTopicTime(void) {
	return (topicTime);
}

unsigned int Channel::getUserLimit() {
	return (userLimit);
}

unsigned int Channel::getUserCount() {
	return (users.size());
}

std::unordered_set<Client *> Channel::getUserList() {
	return (users);
}

void Channel::setTopic(std::string newTopic) {
	topic = newTopic;
}

void Channel::setTopicAuthor(Client *user) {
	if (user)
		topicAuthor = user->getNickname();
}

void Channel::setTopicTime(std::time_t time) {
	topicTime = time;
}

void Channel::setUserLimit(unsigned int newLimit) {
	userLimit = newLimit;
}

bool Channel::checkPassword(std::string input) {
	// FIXME if client provides invalid password send back ERR_BADCHANNELKEY
	if (input == password)
		return (true);
	return (false);
}

bool Channel::validatePassword(std::string password) {
	// FIXME if validation fails, send ERR_INVALIDMODEPARAM or ERR_INVALIDKEY to client
	if (password.empty())
		return (false);
	if (std::string(password).find(' ') != std::string::npos)
		return (false);
	return (true);
}

bool Channel::isAllowedChannelMode(char mode) {
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

bool Channel::addMode(char mode) {
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

bool Channel::delMode(char mode) {
	if (!isAllowedChannelMode(mode))
		return (false);
	channelMode.erase(mode);
	return (true);
}

bool Channel::hasMode(char mode) {
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

bool Channel::userIsJoined(Client *user) {
	if (user && users.find(user) != users.end())
		return (true);
	return (false);
}

bool Channel::userIsOperator(Client *user) {
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
