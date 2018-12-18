#ifndef CircuitBreaker_h__
#define CircuitBreaker_h__

#include "CircuitBreakerHealthPolicy.h"
#include "CircuitBreakerState.h"
#include "../task/Locker.h"

class CircuitBreaker
{
private:
    Locker _locker;

    CircuitBreakerHealthPolicy* policy;
    CircuitBreakerState* state;

    void changeState(CircuitBreakerState* newState);

public:
	CircuitBreaker(CircuitBreakerHealthPolicy* policy);
	virtual ~CircuitBreaker();

    bool isRequestAllowed();
};

#endif // CircuitBreaker_h__
