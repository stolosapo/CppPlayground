#include <string>

#include "TcpClientConfigLoader.h"

using namespace std;

TcpClientConfigLoader::TcpClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

TcpClientConfigLoader::~TcpClientConfigLoader()
{

}

TcpClientConfig* TcpClientConfigLoader::load()
{
	TcpClientConfig* config = new TcpClientConfig;

	this->getSerializer()->loadModelFromFile(config, this->getFilename());

	return config;
}
