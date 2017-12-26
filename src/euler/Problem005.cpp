#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../kernel/converter/Convert.h"

using namespace std;

class Problem005 : public EulerProblem<int>
{
private:
	int run(const int MIN_DIV, const int MAX_DIV, const int BASE_LOWER_NUMBER)
	{
		int min = BASE_LOWER_NUMBER;
		bool found = isEvenlyDivisible(MIN_DIV, MAX_DIV, min);

		while(!found)
		{
			min++;

			found = isEvenlyDivisible(MIN_DIV, MAX_DIV, min);			
		}

		return min;
	}

	bool isEvenlyDivisible(const int MIN_DIV, const int MAX_DIV, int number)
	{
		bool isOK = true;

		for (int i = MIN_DIV; i <= MAX_DIV; ++i)
		{
			if (number % i != 0)
			{
				isOK = false;
				break;
			}
		}

		return isOK;
	}

protected:
	int example()
	{
		const int MIN_DIV = 1;
		const int MAX_DIV = 10;
		const int BASE_LOWER_NUMBER = 1;

		return run(MIN_DIV, MAX_DIV, BASE_LOWER_NUMBER);
	}

	int solve()
	{
		const int MIN_DIV = 1;
		const int MAX_DIV = 20;
		const int BASE_LOWER_NUMBER = 2520;

		return run(MIN_DIV, MAX_DIV, BASE_LOWER_NUMBER);
	}
	
public:
	Problem005(ILogService *logSrv) : EulerProblem(
		logSrv,
		5, 
		"Problem 005", 
		"Smallest multiple", 
		"2520 is the smallest number that can be divided \n"
		"by each of the numbers from 1 to 10 without any remainder. \n"
		"What is the smallest positive number that is \n"
		"evenly divisible by all of the numbers from 1 to 20?")
	{
		solved = true;
		setCorrectAnswer(232792560);
	}

	~Problem005()
	{
		
	}

};