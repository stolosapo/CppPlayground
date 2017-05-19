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
	registerPropertyName(4, "serverHostname", Property::STRING);
	registerPropertyName(5, "serverPort", Property::INT);
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

string TcpClientConfig::getServerHostname()
{
	return getStringProperty("serverHostname");
}

int TcpClientConfig::getServerPort()
{
	return getIntProperty("serverHostname");
}


Model* TcpClientConfig::factory()
{
	return (Model*) new TcpClientConfig;
}
