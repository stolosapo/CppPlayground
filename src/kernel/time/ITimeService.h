#ifndef ITimeService_h__
#define ITimeService_h__

#include <iostream>
#include <stdio.h>
#include <time.h>

#include "../service/IService.h"

using namespace std;

class ITimeService: public IService
{
public:
	ITimeService();
	virtual ~ITimeService();

	virtual time_t rawNow() = 0;
};

#endif // ITimeService_h__
