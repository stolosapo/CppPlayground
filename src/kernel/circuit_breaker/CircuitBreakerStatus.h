#ifndef CircuitBreakerStatus_h__
#define CircuitBreakerStatus_h__


enum CircuitBreakerStatus
{
    CB_NONE = 0,

    CB_CLOSED = 1,

	CB_OPEN = 2,

    CB_HALFOPEN = 3
};


#endif // CircuitBreakerStatus_h__
