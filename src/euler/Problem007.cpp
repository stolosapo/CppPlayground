#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../shared/PrimeFactor.h"

using namespace std;

class Problem007 : public EulerProblem
{
private:
	int run(const int INDEX)
	{
		return PrimeFactor::getByIndex(INDEX);
	}

protected:
	int example()
	{
		const int INDEX = 6;

		return run(INDEX);
	}

	int solve()
	{
		const int INDEX = 10001;

		return run(INDEX);
	}
	
public:
	Problem007(ILogService *logSrv) : EulerProblem(
		logSrv,
		7, 
		"Problem 007", 
		"10001st prime", 
		"By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, \n"
		"we can see that the 6th prime is 13. \n"
		"What is the 10001st prime number?")
	{
		solved = true;
	}

	~Problem007()
	{
		
	}

};