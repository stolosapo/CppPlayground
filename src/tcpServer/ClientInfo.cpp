#include "ClientInfo.h"
#include <string>

using namespace std;

ClientInfo::ClientInfo(TcpStream *stream)
{
	this->stream = stream;
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