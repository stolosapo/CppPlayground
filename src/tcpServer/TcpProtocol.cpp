#include <boost/algorithm/string.hpp>
#include "TcpProtocol.h"


const char* TcpProtocol::PROMPT = "tfk > ";
const char* TcpProtocol::CLIENT_CONNECT = "client_connect";
const char* TcpProtocol::OK = "ok";
const char* TcpProtocol::DENIED = "denied";
const char* TcpProtocol::HELP = "help";
const char* TcpProtocol::EXIT = "exit";
const char* TcpProtocol::SHUTDOWN = "shutdown";

const char* const TcpProtocol::ACK_COMMANDS[] = {
	TcpProtocol::CLIENT_CONNECT,
	TcpProtocol::OK
};

const char* const TcpProtocol::COMMANDS[] = {
	TcpProtocol::PROMPT,
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

bool TcpProtocol::exit(string command)
{
	boost::to_lower(command);

	if ( (((string) EXIT) == command) ||
		 (((string) SHUTDOWN) == command) )
	{
		return true;
	}

	return false;
}

bool TcpProtocol::shutdown(string command)
{
	boost::to_lower(command);

	if ( (((string) SHUTDOWN) == command) )
	{
		return true;
	}

	return false;
}