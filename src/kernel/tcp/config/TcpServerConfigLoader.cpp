#include <string>

#include "TcpServerConfigLoader.h"

using namespace std;

TcpServerConfigLoader::TcpServerConfigLoader(string filename) : IConfigLoader(filename)
{

}

TcpServerConfigLoader::~TcpServerConfigLoader()
{

}

TcpServerConfig* TcpServerConfigLoader::createNewConfigInstance()
{
    return new TcpServerConfig;
}
