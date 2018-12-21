#ifndef CircuitBreakerState_h__
#define CircuitBreakerState_h__

#include "CircuitBreakerStatus.h"
#include "CircuitBreaker_t.h"

class CircuitBreakerState
{
private:
    CircuitBreakerStatus status;

protected:
    CircuitBreaker* cb;

public:
	CircuitBreakerState(CircuitBreaker* cb, CircuitBreakerStatus status);
	virtual ~CircuitBreakerState();

    CircuitBreakerStatus getStatus();

    virtual bool isRequestAllowed() = 0;
};

#endif // CircuitBreakerState_h__
