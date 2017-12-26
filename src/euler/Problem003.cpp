#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../kernel/converter/Convert.h"
#include "../kernel/math/PrimeFactor.h"

using namespace std;

class Problem003 : public EulerProblem<long long>
{
private:
	long long run(long long number)
	{
		return maxPrimeFactorization(number);
	}

	long long maxPrimeFactorization(long long number)
	{
		if (isPrime(number))
		{
			output("Put : ");
			output(Convert<long long>::NumberToString(number));
			output("\n");	
			return number;
		}
		else 
		{
			int baseDiv = 2;
			while (number % baseDiv != 0)
			{
				baseDiv = PrimeFactor::getNextPrime(baseDiv);
			}

			long long numberDiv = number / baseDiv;

			output("Div : ");
			output(Convert<long long>::NumberToString(number));
			output(" / ");
			output(Convert<long long>::NumberToString(baseDiv));
			output(" = ");
			output(Convert<long long>::NumberToString(numberDiv));
			output("\n");
		
			return maxPrimeFactorization(numberDiv);
		}
	}

	bool isPrime(long long number)
	{
		for (int j = 2; j <= number; j++)
		{
			if (number % j == 0 && number != j && j != 1)
			{
				return false;
			}
		}

		return true;
	}

protected:
	long long example()
	{
		return run(13195);
	}

	long long solve()
	{
		return run(600851475143);
	}
	
public:
	Problem003(ILogService *logSrv) : EulerProblem(
		logSrv,
		3, 
		"Problem 003", 
		"Largest prime factor", 
		"The prime factors of 13195 are 5, 7, 13 and 29. \n"
		"What is the largest prime factor of the number 600851475143 ?  \n")
	{
		solved = true;
		setCorrectAnswer(6857);
		
		showOutput = false;	
	}

	~Problem003()
	{
		
	}

};
