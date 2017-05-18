#include "TcpServerConfig.h"

#include <string>

using namespace std;

TcpServerConfig::TcpServerConfig() : IConfig(&factory)
{

}

TcpServerConfig::~TcpServerConfig()
{

}

void TcpServerConfig::registerProperties()
{
	registerPropertyName(1, "serverPort", Property::INT);
	registerPropertyName(2, "serverHostname", Property::STRING);
}

int TcpServerConfig::getServerPort()
{
	return getIntProperty("serverPort");
}

string TcpServerConfig::getServerHostname()
{
	return getStringProperty("serverHostname");
}

Model* TcpServerConfig::factory()
{
	return (Model*) new TcpServerConfig;
}