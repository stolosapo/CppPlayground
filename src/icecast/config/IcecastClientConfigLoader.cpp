#include <string>

#include "IcecastClientConfigLoader.h"

using namespace std;

IcecastClientConfigLoader::IcecastClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

IcecastClientConfigLoader::~IcecastClientConfigLoader()
{

}

IcecastClientConfig* IcecastClientConfigLoader::createNewConfigInstance()
{
	return new IcecastClientConfig;
}
