#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "log/LogServiceFactory.h"
#include "time/TimeServiceFactory.h"
#include "euler/Problem001.cpp"

using namespace std;

int main()
{
	ILogService *srv = LogServiceFactory::create();
	// srv->test();
	
	Problem001 prob001;
	srv->info(prob001.identify());

	prob001.findSolution();
	

	// srv->info("This is an information");
	// srv->debug("This is an debug information");
	// srv->error("This is an error");
	// srv->fatal("This is a fatal error");

	// ITimeService *timeSrv = TimeServiceFactory::create();
	// time_t now = timeSrv->rawNow();
	// struct tm * timeinfo;
	// timeinfo = localtime ( &now );
	// string strTime = asctime (timeinfo);
	// srv->info("Now is " + strTime);
}