#ifndef CircuitBreakerHalfOpenState_h__
#define CircuitBreakerHalfOpenState_h__

#include "CircuitBreakerState.h"

class CircuitBreakerHalfOpenState : public CircuitBreakerState
{
private:
    static const double chance;

public:
	CircuitBreakerHalfOpenState(CircuitBreaker* cb, ITimeService* timeSrv);
	virtual ~CircuitBreakerHalfOpenState();

    virtual bool isRequestAllowed();
};

#endif // CircuitBreakerHalfOpenState_h__
