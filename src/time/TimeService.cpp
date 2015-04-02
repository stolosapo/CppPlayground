#include <iostream>
#include <stdio.h>
#include <time.h>
#include "ITimeService.h"

using namespace std;

class TimeService : public ITimeService
{
public:
	TimeService() : ITimeService()
	{

	}
	
	~TimeService()
	{

	}

	time_t rawNow()
	{
		return time(0);		
	}

};