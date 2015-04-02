#include <iostream>
#include <string>
#include "log/LogServiceFactory.h"

using namespace std;

int main()
{
	ILogService *srv = LogServiceFactory::create();
	srv->test();

	srv->info("This is an information");
	srv->debug("This is an debug information");
	srv->error("This is an error");
	srv->fatal("This is a fatal error");
}