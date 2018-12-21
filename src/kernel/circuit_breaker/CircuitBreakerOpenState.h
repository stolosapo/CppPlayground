#ifndef CircuitBreakerOpenState_h__
#define CircuitBreakerOpenState_h__

#include "CircuitBreakerState.h"

class CircuitBreakerOpenState : public CircuitBreakerState
{
public:
	CircuitBreakerOpenState(CircuitBreaker* cb);
	virtual ~CircuitBreakerOpenState();

    virtual bool isRequestAllowed();
};

#endif // CircuitBreakerOpenState_h__
