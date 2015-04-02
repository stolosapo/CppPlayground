#include <iostream>
#include "log/LogServiceFactory.h"

using namespace std;

int main()
{
	ILogService *srv = LogServiceFactory::create();
	srv->test();
}