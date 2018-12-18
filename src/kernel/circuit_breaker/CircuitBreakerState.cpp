#include "CircuitBreakerState.h"

CircuitBreakerState::CircuitBreakerState(CircuitBreakerStatus status)
    : status(status)
{

}

CircuitBreakerState::~CircuitBreakerState()
{

}

CircuitBreakerStatus CircuitBreakerState::getStatus()
{
    return status;
}
