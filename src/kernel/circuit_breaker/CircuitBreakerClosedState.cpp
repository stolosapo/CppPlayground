#include "CircuitBreakerClosedState.h"
#include "CircuitBreaker.h"

CircuitBreakerClosedState::CircuitBreakerClosedState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, CB_CLOSED)
{

}

CircuitBreakerClosedState::~CircuitBreakerClosedState()
{

}

bool CircuitBreakerClosedState::isRequestAllowed()
{
    if (cb->policy->isHealthy())
    {
        return true;
    }

    /* Change state to OPEN */
    cb->changeState(new CircuitBreakerOpenState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
