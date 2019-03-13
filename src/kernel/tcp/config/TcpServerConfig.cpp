#include "TcpServerConfig.h"

#include <string>

using namespace std;


const char* TcpServerConfig::DEFAULT_HOSTNAME = "localhost";


TcpServerConfig::TcpServerConfig() : IConfig(&factory)
{
	this->registerProperties();
}

TcpServerConfig::TcpServerConfig(ModelFactory modelFactory) : IConfig(modelFactory)
{
	this->registerProperties();
}

TcpServerConfig::~TcpServerConfig()
{

}

void TcpServerConfig::registerProperties()
{
	registerPropertyName(1, "id", INT);
	registerPropertyName(2, "name", STRING);
	registerPropertyName(3, "description", STRING);
	registerPropertyName(4, "hostname", STRING);
	registerPropertyName(5, "port", INT);
	registerPropertyName(6, "poolsize", INT);
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
	return getStringProperty("hostname", string(DEFAULT_HOSTNAME));
}

int TcpServerConfig::getPort()
{
	return getIntProperty("port", DEFAULT_PORT);
}

int TcpServerConfig::getPoolsize()
{
	return getIntProperty("poolsize", DEFAULT_THREAD_POOL_SIZE);
}


Model* TcpServerConfig::factory()
{
	return (Model*) new TcpServerConfig;
}
