#include "Score4ClientConfigLoader.h"


Score4ClientConfigLoader::Score4ClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

Score4ClientConfigLoader::~Score4ClientConfigLoader()
{

}

Score4ClientConfig* Score4ClientConfigLoader::load()
{
	Score4ClientConfig* config = new Score4ClientConfig;

	getSerializer()->loadModelFromFile(config, getFilename());

	return config;
}
