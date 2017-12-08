#include "ITcpProtocol.h"

#include "../../lib/exception/domain/DomainException.h"
#include "../exception/TcpProtocolErrorCode.h"

const char* ITcpProtocol::PROMPT = "tfk> ";

const char* ITcpProtocol::CLIENT_CONNECT = "client_connect";
const char* ITcpProtocol::OK = "ok";
const char* ITcpProtocol::DENIED = "denied";
const char* ITcpProtocol::INVALID_COMMAND = "invalid_command";

const char* ITcpProtocol::HELP = "help";
const char* ITcpProtocol::EXIT = "exit";
const char* ITcpProtocol::SHUTDOWN = "shutdown";


ITcpProtocol::ITcpProtocol(bool isServer) : isServer(isServer)
{

}

ITcpProtocol::~ITcpProtocol()
{
	isServer = false;
}



bool ITcpProtocol::getIsServer()
{
	return isServer;
}



void ITcpProtocol::handshake(ClientInfo *client)
{

}

void ITcpProtocol::authenticate(ClientInfo *client)
{

}


void ITcpProtocol::send(bool escape, ClientInfo *client, string command)
{
	if (escape)
	{
		return;
	}

	client->getStream()->send(command);
}

void ITcpProtocol::receive(bool escape, ClientInfo *client, string expected, DomainErrorCode errorCode)
{
	if (escape)
	{
		return;
	}

	string input = "";
	client->getStream()->receive(input);

	if (input == expected)
	{
		return;
	}

	throw DomainException(errorCode);
}

void ITcpProtocol::serverSend(ClientInfo *client, string command)
{
	send(!isServer, client, command);
}

void ITcpProtocol::serverReceive(ClientInfo *client, string expected, DomainErrorCode errorCode)
{
	receive(!isServer, client, expected, errorCode);
}

void ITcpProtocol::clientSend(ClientInfo *client, string command)
{
	send(isServer, client, command);
}

void ITcpProtocol::clientReceive(ClientInfo *client, string expected, DomainErrorCode errorCode)
{
	receive(isServer, client, expected, errorCode);
}
