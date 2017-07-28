#include "UnitTestSuite.h"
#include "Logger.h"

UnitTestSuite::UnitTestSuite(string description, int methodsToCoverCount) : UnitTest(description)
{
	this->level = 0;
	this->methodsToCoverCount = methodsToCoverCount;
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

		if (!ut->isIgnored())
		{
			ut->test();
		}

		passed &= ut->isPassed();
	}
}

bool UnitTestSuite::report()
{
	string reportMessage = getDescription() + ": " + "\n";

	logTestResults(ignored, passed, reportMessage);

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

void UnitTestSuite::registerCoveredMethod(string methodName)
{
	methodsCovered.push_back(methodName);
}

void UnitTestSuite::registerTest(string description, UnitTestFunction unitTestFunction)
{
	UnitTest* test = new UnitTest(description, unitTestFunction);

	unitTests.push_back(test);
}

void UnitTestSuite::ignoreTest(string description, UnitTestFunction unitTestFunction)
{
	UnitTest* test = new UnitTest(description, unitTestFunction);

	test->setIgnored(true);

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
		else if (!ut->isIgnored() && ut->isPassed())
		{
			curCnt = 1;
		}

		cnt += curCnt;
	}

	return cnt;
}

int UnitTestSuite::getIgnoredCount()
{
	int cnt = 0;

	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it)
	{
		int curCnt = 0;

		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut))
		{
			curCnt = uts->getIgnoredCount();
		}
		else if (ut->isIgnored())
		{
			curCnt = 1;
		}

		cnt += curCnt;
	}

	return cnt;
}

int UnitTestSuite::getMethodsToCoverCount()
{
	int cnt = 0;

	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it)
	{
		int curCnt = 0;

		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut))
		{
			curCnt = uts->getMethodsToCoverCount();
		}
		else
		{
			curCnt = this->methodsToCoverCount;
		}

		cnt += curCnt;
	}

	return cnt;
}

int UnitTestSuite::getMethodsCoveredCount()
{
	int cnt = 0;

	for (vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it)
	{
		int curCnt = 0;

		UnitTest* ut = *it;

		if (UnitTestSuite* uts = dynamic_cast<UnitTestSuite*>(ut))
		{
			curCnt = uts->getMethodsCoveredCount();
		}
		else
		{
			curCnt = methodsCovered.size();
		}

		cnt += curCnt;
	}

	return cnt;
}

double UnitTestSuite::getCoverage()
{
	int total = getMethodsToCoverCount();
	int cur = getMethodsCoveredCount();

	if (total == 0)
	{
		return 0;
	}

	return (100 * cur) / total;
}