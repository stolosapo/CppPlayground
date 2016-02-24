#include <boost/algorithm/string.hpp>
#include "TcpProtocol.h"


const char* TcpProtocol::PROMPT = "tfk > ";

const char* TcpProtocol::CLIENT_CONNECT = "client_connect";
const char* TcpProtocol::OK = "ok";
const char* TcpProtocol::DENIED = "denied";
const char* TcpProtocol::INVALID_COMMAND = "invalid_command";

const char* TcpProtocol::HELP = "help";
const char* TcpProtocol::EXIT = "exit";
const char* TcpProtocol::SHUTDOWN = "shutdown";

const char* const TcpProtocol::ACK_COMMANDS[] = {
	TcpProtocol::CLIENT_CONNECT,
	TcpProtocol::OK,
	TcpProtocol::DENIED,
	TcpProtocol::INVALID_COMMAND
};

const char* const TcpProtocol::COMMANDS[] = {
	TcpProtocol::HELP,
	TcpProtocol::EXIT,
	TcpProtocol::SHUTDOWN
};

TcpProtocol::TcpProtocol()
{

}

TcpProtocol::~TcpProtocol()
{

}




/**********************
 *
 *   PRIVATE METHODS
 *
 **********************/
void TcpProtocol::toLower(string command)
{
	boost::to_lower(command);
}

bool TcpProtocol::exists(const char* const array[], int size, string command)
{
	bool exist = false;

	for (int i = 0; i < size; ++i)
	{
		const char *current = array[i];

		if ((((string) current) == command))
		{
			exist = true;
			break;
		}
	}

	return exist;
}





/**********************
 *
 *    PUBLIC METHODS
 *
 **********************/
bool TcpProtocol::exit(string command)
{
	toLower(command);

	if ( (((string) EXIT) == command) ||
		 (((string) SHUTDOWN) == command) )
	{
		return true;
	}

	return false;
}

bool TcpProtocol::error(string command)
{
	toLower(command);

	if ( (((string) INVALID_COMMAND) == command) )
	{
		return true;
	}

	return false;
}

bool TcpProtocol::shutdown(string command)
{
	toLower(command);

	if ( (((string) SHUTDOWN) == command) )
	{
		return true;
	}

	return false;
}

bool TcpProtocol::validCommand(string command)
{
	toLower(command);

	return exists(COMMANDS, 3, command);
}

bool TcpProtocol::validAckCommand(string command)
{
	toLower(command);

	return exists(ACK_COMMANDS, 4, command);
}
