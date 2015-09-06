#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"

using namespace std;

class Problem001 : public EulerProblem<int>
{
private:
	int *multipliers;

	int run(const int number)
	{
		int current = 0;

		for (int i = number - 1; i >= 0; i--)
		{
			for (int j = 0; j < 2; j++)
			{
				int multiplier = multipliers[j];
				if (i % multiplier == 0)
				{
					current += i;
					break;
				}
			}
		}

		return current;
	}

protected:
	int example()
	{
		return run(10);
	}

	int solve()
	{
		return run(1000);
	}
	
public:
	Problem001(ILogService *logSrv) : EulerProblem(
		logSrv,
		1, 
		"Problem 001", 
		"Multiples of 3 and 5", 
		"If we list all the natural numbers below 10 \n"
		"that are multiples of 3 or 5, we get 3, 5, 6 and 9. \n"
		"The sum of these multiples is 23. \n"
		"Find the sum of all the multiples of 3 or 5 below 1000.")
	{
		solved = true;
				 
		multipliers = new int [2];
		multipliers[0] = 3;
		multipliers[1] = 5;
	}

	~Problem001()
	{
		delete[] multipliers;
	}

};