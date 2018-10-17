#include "Score4ClientConfigLoader.h"


Score4ClientConfigLoader::Score4ClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

Score4ClientConfigLoader::~Score4ClientConfigLoader()
{

}

Score4ClientConfig* Score4ClientConfigLoader::createNewConfigInstance()
{
	return new Score4ClientConfig;
}
