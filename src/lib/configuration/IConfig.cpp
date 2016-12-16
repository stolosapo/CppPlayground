#include "IConfig.h"

using namespace std;

IConfig::IConfig(string fileName, staticFactoryMethod staticFactory) : Model(staticFactory)
{
	this->fileName = fileName;
}

IConfig::~IConfig()
{
	
}