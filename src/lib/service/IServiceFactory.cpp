#include "IServiceFactory.h"

IServiceFactory::IServiceFactory()
{
	this->implementationSelection = "";
}

IServiceFactory::IServiceFactory(string implementationSelection)
{
	this->implementationSelection = implementationSelection;
}

IServiceFactory::~IServiceFactory()
{
	
}