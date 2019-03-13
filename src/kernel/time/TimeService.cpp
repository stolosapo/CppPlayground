#include "TimeService.h"

TimeService::TimeService(): ITimeService()
{

}

TimeService::~TimeService()
{

}

time_t TimeService::rawNow()
{
	return time(0);
}
