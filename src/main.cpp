#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "json/JsonServiceFactory.h"
#include "log/LogServiceFactory.h"
#include "time/TimeServiceFactory.h"

using namespace std;

int main()
{

	ILogService *logSrv = LogServiceFactory::create();
	logSrv->test();

	IJsonService *JsonSrv = JsonServiceFactory::create();
	JsonSrv->test();

	ITimeService *timeSrv = TimeServiceFactory::create();
	time_t now = timeSrv->rawNow();
	struct tm * timeinfo;
	timeinfo = localtime ( &now );
	string strTime = asctime (timeinfo);
	logSrv->info("Now is " + strTime);
}