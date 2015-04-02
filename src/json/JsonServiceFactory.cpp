#include <iostream>
#include "JzonService.cpp"

class JsonServiceFactory
{
public:
	JsonServiceFactory() 
	{

	}

	static IJsonService *create()
	{
		JzonService* srv = new JzonService;
		return  (IJsonService*) srv;
	}
};