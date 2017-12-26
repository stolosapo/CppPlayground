#include <iostream>
#include <string>
#include <math.h>
#include "EulerProblem.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/converter/Convert.h"

using namespace std;

class Problem006 : public EulerProblem<int>
{
private:
	int run(const int MIN, const int MAX)
	{
		int diff = 0;

		int sumOfSq = sumOfSquares(MIN, MAX);
		int sqOfSum = squareOfSum(MIN, MAX);

		diff = sqOfSum - sumOfSq;

		return diff;
	}

	int sumOfSquares(const int MIN, const int MAX)
	{
		int sum = 0;

		for (int i = MIN; i <= MAX; ++i)
		{
			sum = sum + pow(i, 2);
		}

		return sum;
	}

	int squareOfSum(const int MIN, const int MAX)
	{
		int sum = 0;

		for (int i = MIN; i <= MAX; ++i)
		{
			sum = sum + i;
		}

		sum = pow(sum, 2);

		return sum;
	}

protected:
	int example()
	{
		const int MIN = 1;
		const int MAX = 10;

		return run(MIN, MAX);
	}

	int solve()
	{
		const int MIN = 1;
		const int MAX = 100;

		return run(MIN, MAX);
	}
	
public:
	Problem006(ILogService *logSrv) : EulerProblem(
		logSrv,
		6, 
		"Problem 006", 
		"Sum square difference", 
		"The sum of the squares of the first ten natural numbers is, \n"
		"            1^2 + 2^2 + ... + 10^2 = 385 \n"
		"The square of the sum of the first ten natural numbers is, \n"
		"           (1 + 2 + ... + 10)^2 = 55^2 = 3025 \n"
		"Hence the difference between the sum of the squares \n"
		"of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640. \n"
		"Find the difference between the sum of the squares \n"
		"of the first one hundred natural numbers and the square of the sum.")
	{
		solved = true;
		setCorrectAnswer(25164150);
	}

	~Problem006()
	{
		
	}

};