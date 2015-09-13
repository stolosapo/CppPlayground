#include <iostream>
#include <string>
#include <vector>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../shared/convert.h"
#include "../shared/PrimeFactor.h"

using namespace std;

class Problem010 : public EulerProblem<int>
{
private:
	int run(const int BELOW)
	{
		vector<int> upTo = PrimeFactor::upTo(BELOW);
		int sum = 0;

		for (int i = 0; i < upTo.size(); ++i)
		{
			sum += upTo[i];
		}

		return sum;
	}

protected:
	int example()
	{
		const int BELOW = 10;

		return run(BELOW);
	}

	int solve()
	{
		const int BELOW = 2000000;

		return run(BELOW);
	}
	
public:
	Problem010(ILogService *logSrv) : EulerProblem(
		logSrv,
		10, 
		"Problem 010", 
		"Summation of primes", 
		"The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17. \n "
		"Find the sum of all the primes below two million.")
	{
		solved = false;
		// setCorrectAnswer(31875000);

		showExample = true;
		showOutput = true;
	}

	~Problem010()
	{
		
	}

};