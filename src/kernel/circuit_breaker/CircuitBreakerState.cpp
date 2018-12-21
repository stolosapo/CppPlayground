#include "CircuitBreakerState.h"

CircuitBreakerState::CircuitBreakerState(CircuitBreaker* cb, CircuitBreakerStatus status)
    : cb(cb), status(status)
{

}

CircuitBreakerState::~CircuitBreakerState()
{

}

CircuitBreakerStatus CircuitBreakerState::getStatus()
{
    return status;
}
