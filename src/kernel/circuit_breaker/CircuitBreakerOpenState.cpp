#include "CircuitBreakerOpenState.h"
#include "CircuitBreaker.h"

CircuitBreakerOpenState::CircuitBreakerOpenState(CircuitBreaker* cb, ITimeService* timeSrv)
    : CircuitBreakerState(cb, timeSrv, CB_OPEN)
{
    exitTime = timeSrv->rawNow() + openStateTimeoutSec;
}

CircuitBreakerOpenState::~CircuitBreakerOpenState()
{

}

bool CircuitBreakerOpenState::isRequestAllowed()
{

    if (timeSrv->rawNow() <= exitTime)
    {
        return false;
    }

    /* Change state to HALF-OPEN */
    cb->changeState(new CircuitBreakerHalfOpenState(cb, timeSrv));

    /* And check again */
    return cb->isRequestAllowed();
}
