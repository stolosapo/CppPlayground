#include <iostream>
#include <vector>
#include "PrimeFactor.h"

using namespace std;

vector<int> PrimeFactor::upTo(int upperBound)
{
	vector<int> result;
	bool isPrime;

	for (int i = 2; i <= upperBound; i++)
	{
		isPrime = PrimeFactor::isPrime(i);

		if (isPrime)
		{
			result.push_back(i);
		}
	}

	return result;
}

bool PrimeFactor::isPrime(int number)
{
	bool isPrime = true;

	for (int j = 2; j <= number; j++)
	{
		if (number % j == 0 && number != j && j != 1)
		{
			isPrime = false;
			break;	
		}
	}

	return isPrime;
}