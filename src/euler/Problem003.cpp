#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "EulerProblem.h"
#include "../shared/PrimeFactor.h"
#include "../shared/convert.h"

using namespace std;

class Problem003 : public EulerProblem
{
private:
	vector<int> primeNumbers;

	int run(const int len, int bigNumber[])
	{
		int rest = 0;
		int *result = divide(len, bigNumber, 2, rest);

		return result[0];
	}

	int* divide(const int len, int bigNumber[], int divitedBy, int &rest)
	{
		int cur = 0;
		int curDev = 0;
		int curRes = 0;

		int *result = new int[len];

		for (int i = len - 1; i >= 0; i--)
		{
			cur = bigNumber[i] + curRes;
			curDev = cur / divitedBy;
			curRes = cur % divitedBy;

			result[i] = curRes;
		}


		return result;
	}

protected:
	int example()
	{
		const int LEN = 5;
		int bigNumber[LEN] = {
			1, 3, 1, 9, 5
		};

		return run(LEN, bigNumber);
	}

	int solve()
	{
		const int LEN = 12;

		int bigNumber[LEN] = {
			6, 0, 0, 8, 5, 1, 4, 7, 5, 1, 4, 3
		};


		return run(LEN, bigNumber);
	}
	
public:
	Problem003() : EulerProblem(
		3, 
		"Problem 003", 
		"Largest prime factor", 
		"The prime factors of 13195 are 5, 7, 13 and 29. \n"
		"What is the largest prime factor of the number 600851475143 ?  \n")
	{
		// showOutput = false;	

		primeNumbers = PrimeFactor::upTo(1000);
	}

	~Problem003()
	{
		vector<int> clear;
		primeNumbers.swap(clear);
	}

};