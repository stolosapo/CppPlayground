#include <iostream>
#include "JsonServiceFactory.h"
#include "JzonService.cpp"

JsonServiceFactory::JsonServiceFactory() 
{

}

IJsonService *JsonServiceFactory::create()
{
	JzonService* srv = new JzonService;
	return  (IJsonService*) srv;
}