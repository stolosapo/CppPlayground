#ifndef CircuitBreakerOpenState_h__
#define CircuitBreakerOpenState_h__

#include "CircuitBreakerState.h"
#include "../time/ITimeService.h"

class CircuitBreakerOpenState : public CircuitBreakerState
{
private:
    static const int openStateTimeoutSec = 3;

    time_t exitTime;

public:
	CircuitBreakerOpenState(CircuitBreaker* cb, ITimeService* timeSrv);
	virtual ~CircuitBreakerOpenState();

    virtual bool isRequestAllowed();
};

#endif // CircuitBreakerOpenState_h__
