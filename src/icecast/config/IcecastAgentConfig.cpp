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
}

Model* IcecastAgentConfig::factory()
{
	return (Model*) new IcecastAgentConfig;
}
