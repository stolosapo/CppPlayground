#ifndef TimeService_h__
#define TimeService_h__

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "ITimeService.h"

using namespace std;

class TimeService : public ITimeService
{
public:
	TimeService();
	virtual ~TimeService();

	virtual time_t rawNow();

};

#endif // TimeService_h__
