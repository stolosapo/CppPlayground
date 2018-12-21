#include "CircuitBreaker.h"

#include <stdio.h>
#include <stdlib.h>

CircuitBreaker::CircuitBreaker(CircuitBreakerHealthPolicy* policy)
    : policy(policy)
{
    _locker.init();

    // Should initialized to Closed
    state = NULL;

    /* initialize random seed: */
  	srand(time(NULL));
}

CircuitBreaker::~CircuitBreaker()
{
    _locker.destroy();

    if (state != NULL)
    {
        delete state;
    }
}

void CircuitBreaker::changeState(CircuitBreakerState* newState)
{
    _locker.lock();

    if (state != NULL)
    {
        delete state;
    }

    state = newState;

    _locker.unlock();
}

bool CircuitBreaker::isRequestAllowed()
{
    if (state == NULL)
    {
        return false;
    }

    return state->isRequestAllowed();
}
