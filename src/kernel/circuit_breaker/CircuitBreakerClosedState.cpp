#include "CircuitBreakerClosedState.h"
#include "CircuitBreaker.h"

CircuitBreakerClosedState::CircuitBreakerClosedState(CircuitBreaker* cb, ITimeService* timeSrv)
    : CircuitBreakerState(cb, timeSrv, CB_CLOSED)
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
    cb->changeState(new CircuitBreakerOpenState(cb, timeSrv));

    /* And check again */
    return cb->isRequestAllowed();
}
