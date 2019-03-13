#ifndef CircuitBreakerHealthPolicy_h__
#define CircuitBreakerHealthPolicy_h__

class CircuitBreakerHealthPolicy
{
public:
	CircuitBreakerHealthPolicy();
	virtual ~CircuitBreakerHealthPolicy();

    virtual bool isHealthy() = 0;
};

#endif // CircuitBreakerHealthPolicy_h__
