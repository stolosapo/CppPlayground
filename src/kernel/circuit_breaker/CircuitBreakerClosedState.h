#ifndef CircuitBreakerClosedState_h__
#define CircuitBreakerClosedState_h__

#include "CircuitBreakerState.h"

class CircuitBreakerClosedState : public CircuitBreakerState
{
public:
	CircuitBreakerClosedState(CircuitBreaker* cb, ITimeService* timeSrv);
	virtual ~CircuitBreakerClosedState();

    virtual bool isRequestAllowed();
};

#endif // CircuitBreakerClosedState_h__
