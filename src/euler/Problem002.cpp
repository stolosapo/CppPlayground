#include <iostream>
#include <string>
#include "EulerProblem.h"
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

			if (newTerm > limit)
				break;

			if (newTerm % 2 == 0)
				sum += newTerm;

			cnt++;
			
		}

		return sum;
	}

protected:
	void example()
	{
		long current = run(90);
		cout << "Example : " << current << endl;
	}

	void solve()
	{
		long current = run(4000000);
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