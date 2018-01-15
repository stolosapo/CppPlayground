#include "Score4ServerConfigLoader.h"


Score4ServerConfigLoader::Score4ServerConfigLoader(string filename) : IConfigLoader(filename)
{

}

Score4ServerConfigLoader::~Score4ServerConfigLoader()
{

}

Score4ServerConfig* Score4ServerConfigLoader::load()
{
	Score4ServerConfig* config = new Score4ServerConfig;

	getSerializer()->loadModelFromFile(config, getFilename());

	return config;
}
