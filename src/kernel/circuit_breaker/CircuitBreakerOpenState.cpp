#include "CircuitBreakerOpenState.h"
#include "CircuitBreaker.h"

CircuitBreakerOpenState::CircuitBreakerOpenState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, CB_OPEN)
{

}

CircuitBreakerOpenState::~CircuitBreakerOpenState()
{

}

bool CircuitBreakerOpenState::isRequestAllowed()
{

}
