#include <iostream>
#include "json/JsonServiceFactory.h"
#include <string>
#include "log/LogServiceFactory.h"

using namespace std;

int main()
{

	ILogService *srv = LogServiceFactory::create();
	srv->test();

	IJsonService* srv = JsonServiceFactory::create();
	srv->test();

}