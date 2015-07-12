#include <iostream>
#include <string>
#include "EulerProblem.h"

using namespace std;

class Problem001 : public EulerProblem
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
	void example()
	{
		int current = run(10);
		cout << "Example : " << current << endl;
	}

	void solve()
	{
		int current = run(1000);
		cout << current;
	}
	
public:
	Problem001() : EulerProblem(
		1, 
		"Problem 001", 
		"Multiples of 3 and 5", 
		"If we list all the natural numbers below 10 \n"
		"that are multiples of 3 or 5, we get 3, 5, 6 and 9. \n"
		"The sum of these multiples is 23. \n"
		"Find the sum of all the multiples of 3 or 5 below 1000.")
	{
		multipliers = new int [2];
		multipliers[0] = 3;
		multipliers[1] = 5;
	}

	~Problem001()
	{
		delete multipliers;
	}

};