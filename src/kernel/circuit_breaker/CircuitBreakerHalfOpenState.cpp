#include "CircuitBreakerHalfOpenState.h"
#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

CircuitBreakerHalfOpenState::CircuitBreakerHalfOpenState(CircuitBreaker* cb)
    : CircuitBreakerState(cb, CB_HALFOPEN)
{

}

CircuitBreakerHalfOpenState::~CircuitBreakerHalfOpenState()
{

}

bool CircuitBreakerHalfOpenState::isRequestAllowed()
{
    if (!cb->policy->isHealthy())
    {
        return (double) rand() <= chance;
    }

    /* Change state to OPEN */
    cb->changeState(new CircuitBreakerClosedState(cb));

    /* And check again */
    return cb->isRequestAllowed();
}
