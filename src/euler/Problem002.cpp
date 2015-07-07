#include <iostream>
#include <string>
#include "EulerProblem.h"

using namespace std;

class Problem002 : public EulerProblem
{
private:
	long run(const long limit)
	{
		long onePrev = 2L;
		long twoPrev = 1L;
		long newTerm = onePrev + twoPrev;
		long sum = onePrev + twoPrev + newTerm;
		bool go = true;
		long cnt = 3L;

		while (cnt <= limit)
		{
			/*
			cout << "onePrev:" << onePrev 
				<< " twoPrev:" << twoPrev
				<< " newTerm:" << newTerm
				<< " sum:" << sum 
				<< " cnt:" << cnt
				<< endl << endl;
			*/

			twoPrev = onePrev;
			onePrev = newTerm;
			
			newTerm = onePrev + twoPrev;
			
			sum += newTerm;	
			cnt++;

			if (cnt == limit)
				break;
		}

		return sum;
	}

protected:
	void example()
	{
		long current = run(10L);
		cout << "Example : " << current << endl;
	}

	void solve()
	{
		long current = run(4000000L);
		cout << current << endl;
	}
	
public:
	Problem002() : EulerProblem(
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
		
	}

	~Problem002()
	{

	}

};