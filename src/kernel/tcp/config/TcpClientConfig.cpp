#include "TcpClientConfig.h"

#include <string>

using namespace std;


const char* TcpClientConfig::DEFAULT_SERVERNAME = "localhost";


TcpClientConfig::TcpClientConfig() : IConfig(&factory)
{
	this->registerProperties();
}

TcpClientConfig::TcpClientConfig(staticFactoryMethod staticFactory) : IConfig(staticFactory)
{
	this->registerProperties();
}

TcpClientConfig::~TcpClientConfig()
{

}

void TcpClientConfig::registerProperties()
{
	registerPropertyName(1, "id", INT);
	registerPropertyName(2, "name", STRING);
	registerPropertyName(3, "description", STRING);
	registerPropertyName(4, "servername", STRING);
	registerPropertyName(5, "serverport", INT);
}

int TcpClientConfig::getId()
{
	return getIntProperty("id");
}

string TcpClientConfig::getName()
{
	return getStringProperty("name");
}

string TcpClientConfig::getDescription()
{
	return getStringProperty("description");
}

string TcpClientConfig::getServerName()
{
	return getStringProperty("servername", string(DEFAULT_SERVERNAME));
}

int TcpClientConfig::getServerPort()
{
	return getIntProperty("serverport", DEFAULT_PORT);
}


Model* TcpClientConfig::factory()
{
	return (Model*) new TcpClientConfig;
}
