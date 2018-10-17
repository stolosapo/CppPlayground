#include <string>

#include "TcpClientConfigLoader.h"

using namespace std;

TcpClientConfigLoader::TcpClientConfigLoader(string filename) : IConfigLoader(filename)
{

}

TcpClientConfigLoader::~TcpClientConfigLoader()
{

}

TcpClientConfig* TcpClientConfigLoader::createNewConfigInstance()
{
	return new TcpClientConfig;
}
