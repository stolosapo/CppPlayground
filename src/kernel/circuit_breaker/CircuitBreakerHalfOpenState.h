#ifndef CircuitBreakerHalfOpenState_h__
#define CircuitBreakerHalfOpenState_h__

#include "CircuitBreakerState.h"

class CircuitBreakerHalfOpenState : public CircuitBreakerState
{
private:
    static const double chance = 0.02;

public:
	CircuitBreakerHalfOpenState(CircuitBreaker* cb);
	virtual ~CircuitBreakerHalfOpenState();

    virtual bool isRequestAllowed();
};

#endif // CircuitBreakerHalfOpenState_h__
