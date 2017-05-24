#include "TcpClientConfig.h"

#include <string>

using namespace std;

TcpClientConfig::TcpClientConfig() : IConfig(&factory)
{
	this->registerProperties();
}

TcpClientConfig::~TcpClientConfig()
{

}

void TcpClientConfig::registerProperties()
{
	registerPropertyName(1, "id", Property::INT);
	registerPropertyName(2, "name", Property::STRING);
	registerPropertyName(3, "description", Property::STRING);
	registerPropertyName(4, "servername", Property::STRING);
	registerPropertyName(5, "serverport", Property::INT);
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
	return getStringProperty("servername");
}

int TcpClientConfig::getServerPort()
{
	return getIntProperty("serverport");
}


Model* TcpClientConfig::factory()
{
	return (Model*) new TcpClientConfig;
}
