#include "Score4ClientConfig.h"


Score4ClientConfig::Score4ClientConfig() : TcpClientConfig(&factory)
{
	
}

Score4ClientConfig::~Score4ClientConfig()
{

}

void Score4ClientConfig::registerProperties()
{
	TcpClientConfig::registerProperties();
}

Model* Score4ClientConfig::factory()
{
	return (Model*) new Score4ClientConfig;
}
