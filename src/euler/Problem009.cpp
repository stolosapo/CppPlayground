#include <iostream>
#include <string>
#include <math.h>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../lib/converter/convert.h"

using namespace std;

class Problem009 : public EulerProblem<int>
{
private:
	int run(const int TRIPPLET_SUM)
	{
		int product = 0;

		int sum = 0;
		bool isTriplet = false;

		bool found = false;

		for (int a = 1; a <= TRIPPLET_SUM; ++a)
		{
			for (int b = 1; b <= (TRIPPLET_SUM - a); ++b)
			{
				for (int c = 1; c <= (TRIPPLET_SUM - a - b); ++c)
				{
					sum = a + b + c;
					isTriplet = isPythagoreanTriplet(a, b, c);

					if (sum == TRIPPLET_SUM && isTriplet)
					{
						product = a * b * c;

						output(Convert<int>::NumberToString(a));
						output(" * ");
						output(Convert<int>::NumberToString(b));
						output(" * ");
						output(Convert<int>::NumberToString(c));
						output(" = ");


						found = true;
						break;
					}
				}

				if (found)
				{
					break;
				}
			}

			if (found)
			{
				break;
			}
		}

		return product;
	}

	bool isPythagoreanTriplet(int a, int b, int c)
	{
		int sqA = pow(a, 2);
		int sqB = pow(b, 2);
		int sqC = pow(c, 2);

		int sqAB = sqA + sqB;

		if (sqAB == sqC)
		{
			return true;
		}

		return false;
	}

protected:
	int example()
	{
		const int TRIPPLET_SUM = 12;

		return run(TRIPPLET_SUM);
	}

	int solve()
	{
		const int TRIPPLET_SUM = 1000;

		return run(TRIPPLET_SUM);
	}
	
public:
	Problem009(ILogService *logSrv) : EulerProblem(
		logSrv,
		9, 
		"Problem 009", 
		"Special Pythagorean triplet", 
		"A Pythagorean triplet is a set of three natural numbers, a < b < c, \n "
		"for which,  a^2 + b^2 = c^2 \n"
		"For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2. \n"
		"There exists exactly one Pythagorean triplet for which a + b + c = 1000. \n"
		"Find the product abc. \n")
	{
		solved = true;
		setCorrectAnswer(31875000);

		showExample = true;
		showOutput = true;
	}

	~Problem009()
	{
		
	}

};