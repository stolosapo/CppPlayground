#include "UnitTestSuite.h"
#include "Logger.h"

UnitTestSuite::UnitTestSuite(string description) : UnitTest(description)
{
	this->level = 0;
}

UnitTestSuite::~UnitTestSuite()
{

}

void UnitTestSuite::test()
{
	/* Register all unit tests */
	registerTests();

	/* Run all tests */
	for(vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); it++)
	{
		UnitTest* ut = *it;

		ut->test();

		passed &= ut->isPassed();
	}
}

bool UnitTestSuite::report()
{
	string reportMessage = getDescription() + ": " + "\n";

	logTestResults(passed, reportMessage);

	/* Report all tests */
	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it) 
	{
		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut)) 
		{
			uts->setLevel(level + 1);
		}

		for (int i = 0; i < level; ++i)
		{
			cout << "\t";
		}

		ut->report();
	}

	return passed;
}

void UnitTestSuite::registerTest(string description, UnitTestFunction unitTestFunction)
{
	UnitTest* test = new UnitTest(description, unitTestFunction);

	unitTests.push_back(test);
}

void UnitTestSuite::registerTest(UnitTest* test)
{
	unitTests.push_back(test);
}

void UnitTestSuite::setLevel(int level)
{
	this->level = level;
}

int UnitTestSuite::getCount()
{
	int cnt = 0;

	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it) 
	{
		int curCnt = 1;

		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut)) 
		{
			curCnt = uts->getCount();
		}

		cnt += curCnt;
	}

	return cnt;
}

int UnitTestSuite::getPassedCount()
{
	int cnt = 0;

	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it) 
	{
		int curCnt = 0;

		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut)) 
		{
			curCnt = uts->getPassedCount();
		}
		else if (ut->isPassed())
		{
			curCnt = 1;
		}

		cnt += curCnt;
	}

	return cnt;
}