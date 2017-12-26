#include <string>
#include <iostream>
#include "ClientInfo.h"

#include "../kernel/converter/Convert.h"

using namespace std;

ClientInfo::ClientInfo(void *server, TcpStream *stream, Thread *thread, int index)
{
	this->index = index;

	this->stream = stream;
	this->server = server;
	this->thread = thread;
}

ClientInfo::ClientInfo(void *server, TcpStream *stream, int index)
{
	this->index = index;

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


int ClientInfo::getIndex()
{
	return index;
}

Thread* ClientInfo::getThread()
{
	return thread;
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

string ClientInfo::getIdentity()
{
	string strIndex = Convert<int>::NumberToString(index);

	if (thread == NULL)
	{
		return strIndex;
	}

	return strIndex + " - " + thread->getStringId();
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
