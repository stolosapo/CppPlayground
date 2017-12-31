#include <string>

#include "TcpServerConfigLoader.h"

using namespace std;

TcpServerConfigLoader::TcpServerConfigLoader(string filename) : IConfigLoader(filename)
{

}

TcpServerConfigLoader::~TcpServerConfigLoader()
{

}

TcpServerConfig* TcpServerConfigLoader::load()
{
	TcpServerConfig* config = new TcpServerConfig;

	this->getSerializer()->loadModelFromFile(config, this->getFilename());

	return config;
}
