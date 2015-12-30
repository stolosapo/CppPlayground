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

int PrimeFactor::getByIndex(int index)
{
	int cnt = 0;
	int i = 2;
	int primeNumber = 0;
	bool isPrime;

	while(cnt < index)
	{
		isPrime = PrimeFactor::isPrime(i);

		if (isPrime)
		{
			cnt++;
			primeNumber = i;
		}

		i++;
	}

	return primeNumber;
}


int PrimeFactor::getNextPrime(int prime)
{
	prime++;
	
	if (PrimeFactor::isPrime(prime))
	{
		return prime;
	}

	while (!PrimeFactor::isPrime(prime))
	{
		prime++;
	}

	return prime;
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
