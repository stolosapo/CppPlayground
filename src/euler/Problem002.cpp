#include <iostream>
#include <string>
#include "EulerProblem.h"
#include "../log/ILogService.h"
#include "../shared/convert.h"

using namespace std;

class Problem002 : public EulerProblem
{
private:
	int run(const int limit)
	{
		int onePrev = 2;
		int twoPrev = 1;
		int newTerm = onePrev + twoPrev;
		int sum = onePrev;
		bool go = true;
		int cnt = 3;
		
		while (newTerm <= limit)
		{
			
			output("onePrev:");
			output(Convert<int>::NumberToString(onePrev));
			output(" twoPrev:");
			output(Convert<int>::NumberToString(twoPrev));
			output(" newTerm:");
			output(Convert<int>::NumberToString(newTerm));
			output(" sum:");
			output(Convert<int>::NumberToString(sum));
			output(" cnt:");
			output(Convert<int>::NumberToString(cnt));
			output("\n\n");	

			twoPrev = onePrev;
			onePrev = newTerm;
			newTerm = onePrev + twoPrev;

			if (newTerm > limit)
				break;

			if (newTerm % 2 == 0)
				sum += newTerm;

			cnt++;
			
		}

		return sum;
	}

protected:
	int example()
	{
		return run(90);
	}

	int solve()
	{
		return run(4000000);
	}
	
public:
	Problem002(ILogService *logSrv) : EulerProblem(
		logSrv,
		2, 
		"Problem 002", 
		"Even Fibonacci numbers", 
		"Each new term in the Fibonacci sequence is generated \n"
		"by adding the previous two terms.  \n"
		"By starting with 1 and 2, the first 10 terms will be: \n"
		"1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ... \n"
		"By considering the terms in the Fibonacci sequence \n"
		"whose values do not exceed four million, \n"
		"find the sum of the even-valued terms.")
	{
		showOutput = false;	
	}

	~Problem002()
	{

	}

};