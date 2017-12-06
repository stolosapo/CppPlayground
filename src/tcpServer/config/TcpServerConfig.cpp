#include "TcpServerConfig.h"

#include <string>

using namespace std;


const char* TcpServerConfig::DEFAULT_HOSTNAME = "localhost";


TcpServerConfig::TcpServerConfig() : IConfig(&factory)
{
	this->registerProperties();
}

TcpServerConfig::~TcpServerConfig()
{

}

void TcpServerConfig::registerProperties()
{
	registerPropertyName(1, "id", Property::INT);
	registerPropertyName(2, "name", Property::STRING);
	registerPropertyName(3, "description", Property::STRING);
	registerPropertyName(4, "hostname", Property::STRING);
	registerPropertyName(5, "port", Property::INT);
	registerPropertyName(6, "poolsize", Property::INT);
}

int TcpServerConfig::getId()
{
	return getIntProperty("id");
}

string TcpServerConfig::getName()
{
	return getStringProperty("name");
}

string TcpServerConfig::getDescription()
{
	return getStringProperty("description");
}

string TcpServerConfig::getHostname()
{
	string h = getStringProperty("hostname");

	if (h == "")
	{
		return string(DEFAULT_HOSTNAME);
	}

	return h;
}

int TcpServerConfig::getPort()
{
	int p = getIntProperty("port");

	if (p == 0)
	{
		return DEFAULT_PORT;
	}

	return p;
}

int TcpServerConfig::getPoolsize()
{
	int p = getIntProperty("poolsize");

	if (p == 0)
	{
		return DEFAULT_THREAD_POOL_SIZE;
	}

	return p;
}


Model* TcpServerConfig::factory()
{
	return (Model*) new TcpServerConfig;
}
