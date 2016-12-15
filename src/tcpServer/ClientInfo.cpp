#include "ClientInfo.h"
#include <string>

using namespace std;

ClientInfo::ClientInfo(void *server, TcpStream *stream)
{
	this->stream = stream;
	this->server = server;
}

ClientInfo::~ClientInfo()
{
	if (stream != NULL)
	{
		delete stream;
	}
}


string ClientInfo::getName()
{
	return name;
}

string ClientInfo::getIp()
{
	return ip;
}

string ClientInfo::getHostname()
{
	return hostname;
}

TcpStream* ClientInfo::getStream()
{
	return stream;
}

void* ClientInfo::getServer()
{
	return server;
}


void ClientInfo::setName(string name)
{
	this->name = name;
}

void ClientInfo::setIp(string ip)
{
	this->ip = ip;
}

void ClientInfo::setHostname(string hostname)
{
	this->hostname = hostname;
}