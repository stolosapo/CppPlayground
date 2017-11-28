#include <string>
#include <iostream>
#include "ClientInfo.h"

using namespace std;

ClientInfo::ClientInfo(void *server, TcpStream *stream, Thread *thread, int index)
{
	this->index = index;

	this->stream = stream;
	this->server = server;
	this->thread = thread;
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

long ClientInfo::getThreadNumber()
{
	return threadNumber;
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

TcpStream* ClientInfo::getStream()
{
	return stream;
}

void* ClientInfo::getServer()
{
	return server;
}

void ClientInfo::setThreadNumber(long threadNumber)
{
	this->threadNumber = threadNumber;
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
