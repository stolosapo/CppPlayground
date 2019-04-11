#include "CircuitBreakerHalfOpenState.h"
#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

const double CircuitBreakerHalfOpenState::chance = 0.02;

CircuitBreakerHalfOpenState::CircuitBreakerHalfOpenState(CircuitBreaker* cb, ITimeService* timeSrv)
    : CircuitBreakerState(cb, timeSrv, CB_HALFOPEN)
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

    /* Change state to CLOSED */
    cb->changeState(new CircuitBreakerClosedState(cb, timeSrv));

    /* And check again */
    return cb->isRequestAllowed();
}
