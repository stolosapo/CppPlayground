#include <iostream>
#include <string>
#include "json/JsonServiceFactory.h"
#include "log/LogServiceFactory.h"

using namespace std;

int main()
{

	ILogService *logSrv = LogServiceFactory::create();
	logSrv->test();

	IJsonService *JsonSrv = JsonServiceFactory::create();
	JsonSrv->test();

}