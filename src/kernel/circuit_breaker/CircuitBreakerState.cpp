#include "CircuitBreakerState.h"

CircuitBreakerState::CircuitBreakerState(CircuitBreaker* cb, ITimeService* timeSrv, CircuitBreakerStatus status)
    : cb(cb), timeSrv(timeSrv), status(status)
{

}

CircuitBreakerState::~CircuitBreakerState()
{

}

CircuitBreakerStatus CircuitBreakerState::getStatus()
{
    return status;
}
