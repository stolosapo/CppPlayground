#include "CircuitBreakerClosedState.h"

CircuitBreakerClosedState::CircuitBreakerClosedState()
    : CircuitBreakerState(CB_CLOSED)
{

}

CircuitBreakerClosedState::~CircuitBreakerClosedState()
{

}

bool CircuitBreakerClosedState::isRequestAllowed()
{

}
