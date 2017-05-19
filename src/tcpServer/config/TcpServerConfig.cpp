#include "TcpServerConfig.h"

#include <string>

using namespace std;

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
	registerPropertyName(5, "port", Property::STRING);
	registerPropertyName(6, "poolsize", Property::STRING);
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
	return getStringProperty("hostname");
}

int TcpServerConfig::getPort()
{
	return getIntProperty("port");
}

int TcpServerConfig::getPoolsize()
{
	return getIntProperty("poolsize");
}


Model* TcpServerConfig::factory()
{
	return (Model*) new TcpServerConfig;
}
