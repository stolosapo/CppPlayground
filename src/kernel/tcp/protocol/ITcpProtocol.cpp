#include "ITcpProtocol.h"

#include "../../exception/domain/DomainException.h"
#include "../exception/TcpProtocolErrorCode.h"

const char* ITcpProtocol::PROMPT = "tfk> ";

const char* ITcpProtocol::CLIENT_CONNECT = "client_connect";
const char* ITcpProtocol::OK = "ok";
const char* ITcpProtocol::DENIED = "denied";
const char* ITcpProtocol::ERROR = "error";

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


bool ITcpProtocol::isHelp(string command)
{
	return command == string(HELP);
}

string ITcpProtocol::help()
{
	return "";
}

bool ITcpProtocol::exit(string command)
{
	return command == string(EXIT);
}

bool ITcpProtocol::shutdown(string command)
{
	return command == string(SHUTDOWN);
}

bool ITcpProtocol::error(string command)
{
	return command == string(ERROR);
}

void ITcpProtocol::error(ClientInfo *client)
{
	client->getStream()->send(string(ERROR));
}

string ITcpProtocol::prompt()
{
	return string(PROMPT);
}

bool ITcpProtocol::getIsServer()
{
	return isServer;
}

void ITcpProtocol::handshake(ClientInfo *client)
{
	clientSend(client, CLIENT_CONNECT);
	serverReceive(client, CLIENT_CONNECT, TcpProtocolErrorCode::TCP0001);

	serverSend(client, OK);
	clientReceive(client, OK, TcpProtocolErrorCode::TCP0001);
}

void ITcpProtocol::authenticate(ClientInfo *client)
{

}


void ITcpProtocol::send(bool escape, ClientInfo *client, const char* command)
{
	if (escape)
	{
		return;
	}

	client->getStream()->send(command);
}

void ITcpProtocol::receive(bool escape, ClientInfo *client, const char* expected, const DomainErrorCode& errorCode)
{
	if (escape)
	{
		return;
	}

	string input = "";
	client->getStream()->receive(input);

	if (input == string(expected))
	{
		return;
	}

	throw DomainException(errorCode);
}

void ITcpProtocol::serverSend(ClientInfo *client, const char* command)
{
	send(!isServer, client, command);
}

void ITcpProtocol::serverReceive(ClientInfo *client, const char* expected, const DomainErrorCode& errorCode)
{
	receive(!isServer, client, expected, errorCode);
}

void ITcpProtocol::clientSend(ClientInfo *client, const char* command)
{
	send(isServer, client, command);
}

void ITcpProtocol::clientReceive(ClientInfo *client, const char* expected, const DomainErrorCode& errorCode)
{
	receive(isServer, client, expected, errorCode);
}
