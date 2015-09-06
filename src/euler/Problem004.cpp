#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../shared/convert.h"

using namespace std;

class Problem004 : public EulerProblem<int>
{
private:
	bool isPalindrome(int number)
	{
		bool isOK = false;
		string str = Convert<int>::NumberToString(number);
		int len = str.length();
		int last = len - 1;
		int mid;
		string a;
		string b;

		if (len % 2 == 0)
		{
			mid = len / 2;

			for (int i = 0; i < mid; ++i)
			{
				a = str[i];
				b = str[last - i];
				if (a != b)
				{
					isOK = false;
					break;
				}
				else 
				{
					isOK = true;
				}
			}
		}

		return isOK;
	}

	int run(const int BASE, const int TOP)
	{
		int x;
		int a = 0;
		int b = 0;

		int maxA = 0;
		int maxB = 0;
		int maxX = 0;

		int i = 0;
		int j = 0;

		while (a <= TOP)
		{
			a = BASE + i;
			if (a <= TOP)
			{
				j = 0;
				b = 0;
				while (b <= TOP)
				{
					b = BASE + j;

					if (b <= TOP)
					{
						x = a * b;

						if (isPalindrome(x))
						{
							if (x > maxX)
							{
								maxA = a;
								maxB = b;

								maxX = x;
							}
						}

						j++;
					}

				}

				i++;
			}
		}

		output(Convert<int>::NumberToString(maxA));
		output(" x ");
		output(Convert<int>::NumberToString(maxB));
		output(" = \n");

		return maxA * maxB;
	}

protected:
	int example()
	{
		const int BASE = 10;
		const int TOP = 99;

		return run(BASE, TOP);
	}

	int solve()
	{
		const int BASE = 100;
		const int TOP = 999;

		return run(BASE, TOP);
	}
	
public:
	Problem004(ILogService *logSrv) : EulerProblem(
		logSrv,
		4, 
		"Problem 004", 
		"Largest palindrome product", 
		"A palindromic number reads the same both ways. \n"
		"The largest palindrome made from the product of two 2-digit \n"
		"numbers is 9009 = 91 × 99. \n"
		"Find the largest palindrome made from the product of two 3-digit numbers.")
	{
		solved = true;
		
		setShowOutput(false);
	}

	~Problem004()
	{
		
	}

};