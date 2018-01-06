#include "Score4ServerConfig.h"


Score4ServerConfig::Score4ServerConfig() : TcpClientConfig(&factory)
{
	
}

Score4ServerConfig::~Score4ServerConfig()
{

}

void Score4ServerConfig::registerProperties()
{
	TcpClientConfig::registerProperties();
}

Model* Score4ServerConfig::factory()
{
	return (Model*) new Score4ServerConfig;
}
