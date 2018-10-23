#include "IcecastAgentConfig.h"

#include <string>

using namespace std;

IcecastAgentConfig::IcecastAgentConfig() : TcpServerConfig(&factory)
{
	this->registerProperties();
}

IcecastAgentConfig::~IcecastAgentConfig()
{

}

void IcecastAgentConfig::registerProperties()
{
	TcpServerConfig::registerProperties();

    this->registerPropertyName(20, "icecast_config", STRING);
}

string IcecastAgentConfig::getIcecastConfig()
{
    string value = getStringProperty("icecast_config");

    if (value == "")
    {
        return "icecast.config";
    }

    return value;
}

Model* IcecastAgentConfig::factory()
{
	return (Model*) new IcecastAgentConfig;
}
