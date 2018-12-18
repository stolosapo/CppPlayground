#ifndef CircuitBreakerState_h__
#define CircuitBreakerState_h__

#include "CircuitBreakerStatus.h"

class CircuitBreakerState
{
private:
    CircuitBreakerStatus status;

public:
	CircuitBreakerState(CircuitBreakerStatus status);
	virtual ~CircuitBreakerState();

    CircuitBreakerStatus getStatus();

    virtual bool isRequestAllowed() = 0;
};

#endif // CircuitBreakerState_h__
