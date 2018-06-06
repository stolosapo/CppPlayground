#include <string>

#include "IcecastClientConfigLoader.h"

using namespace std;

IcecastClientConfigLoader::IcecastClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

IcecastClientConfigLoader::~IcecastClientConfigLoader()
{

}

IcecastClientConfig* IcecastClientConfigLoader::load()
{
	IcecastClientConfig* config = new IcecastClientConfig;

	this->getSerializer()->loadModelFromFile(config, this->getFilename());

	return config;
}
