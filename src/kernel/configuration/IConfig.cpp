#include "IConfig.h"

using namespace std;

IConfig::IConfig(staticFactoryMethod staticFactory) : Model(staticFactory)
{

}

IConfig::~IConfig()
{
	
}