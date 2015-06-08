#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "log/LogServiceFactory.h"
#include "time/TimeServiceFactory.h"
#include "menu/MenuFactory.h"

using namespace std;

int main()
{
	ILogService *srv = LogServiceFactory::create();
	srv->test();

	srv->info("This is an information");
	srv->debug("This is an debug information");
	srv->error("This is an error");
	srv->fatal("This is a fatal error");

	ITimeService *timeSrv = TimeServiceFactory::create();
	time_t now = timeSrv->rawNow();
	struct tm * timeinfo;
	timeinfo = localtime ( &now );
	string strTime = asctime (timeinfo);
	srv->info("Now is " + strTime);

	MenuFactory::print();
}