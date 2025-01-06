# ft_irc

<img src="https://github.com/dardangerguri/ft_irc/blob/master/IRC_BOYS-MOD.png" alt="IRC_BOYS-MOD" width="600" height="400"/>

## About the project

The `ft_irc` project is an implementation of an IRC (Internet Relay Chat) server in C++. The objective is to reproduce the functionality of a real IRC server, allowing multiple clients to connect, join channels, and communicate in real-time.

### Project Features

- **Multi-client Handling**: Supports multiple clients connecting simultaneously without hanging.
- **Channel Management**: Clients can create, join, and leave channels.
- **Private Messaging**: Supports private messages between users.
- **Channel Operator and User Roles**: Distinguishes between normal users and operators, with specific commands for operators.
- **Command Support**: Implements essential IRC commands such as `JOIN`, `PRIVMSG`, `KICK`, and more.

## Running the Project

To run the project, follow these steps:

1. Clone the repository

   ```bash
   git clone https://github.com/dardangerguri/ft_irc.git
   cd ft_irc
   ```

2. Compile the server by running `make`
   
3. Start the IRC server by running the server executable with the desired port number and server password
   ```bash
   ./ircserv <port> <password>
   ```

4. Connect with an IRC Client or connect using netcat

     If you connect with an IRC Client we recommend using irssi
      ```bash
      irssi
      ```
      and connect
      ```bash
      /connect 127.0.0.1 <port> <password> [<nick>]
      ```
   
      If you connect using netcat:
      ```bash
      nc -c localhost <port>
      ```

## Usage Examples

Here are some common IRC commands you can use after connecting:

1. **Set Nickname**:

   ```bash
   /nick YourNickname
   ```

   <img src="https://github.com/dardangerguri/ft_irc/blob/master/SetNickname.png" alt="SetNickname" width="350"/>

2. **Join Channel**

   ```bash
   /join #channelname
   ```

   <img src="https://github.com/dardangerguri/ft_irc/blob/master/JoinChannel.png" alt="JoinChannel" width="500"/>

3. **Send a Private Message**

   ```BASH
   /msg Username The message to send
   ```

    <img src="https://github.com/dardangerguri/ft_irc/blob/master/PrivateMessage.png" alt="PrivateMessage" width="600"/>

## Contributors

   - [Dardan Gërguri](https://github.com/dardangerguri)
   - [Joonas Henriksson](https://github.com/jnsh/)
   - [Aleksander Otsala](https://github.com/kenlies)
