#include "Score4ServerConfigLoader.h"


Score4ServerConfigLoader::Score4ServerConfigLoader(string filename) : IConfigLoader(filename)
{

}

Score4ServerConfigLoader::~Score4ServerConfigLoader()
{

}

Score4ServerConfig* Score4ServerConfigLoader::createNewConfigInstance()
{
	return new Score4ServerConfig;
}
