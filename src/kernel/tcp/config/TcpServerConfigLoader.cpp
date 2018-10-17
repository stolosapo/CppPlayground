#include <string>

#include "TcpServerConfigLoader.h"
#include "../../utils/FileHelper.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"

using namespace std;

TcpServerConfigLoader::TcpServerConfigLoader(string filename) : IConfigLoader(filename)
{

}

TcpServerConfigLoader::~TcpServerConfigLoader()
{

}

TcpServerConfig* TcpServerConfigLoader::load()
{
    if (!FileHelper::exists(getFilename().c_str()))
    {
        throw DomainException(GeneralDomainErrorCode::GNR0001, getFilename().c_str());
    }

	TcpServerConfig* config = new TcpServerConfig;

	this->getSerializer()->loadModelFromFile(config, this->getFilename());

	return config;
}
