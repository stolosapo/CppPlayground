#include "UnitTestSuite.h"

UnitTestSuite::UnitTestSuite(string description) : UnitTest(description)
{

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
	report();

	/* Report all tests */
	for(vector<UnitTest*>::iterator it = unitTests.begin(); it != unitTests.end(); ++it) 
	{
		UnitTest* ut = *it;

		ut->report();
	}

	return passed;
}

void UnitTestSuite::registerTest(string description, UnitTestFunction unitTestFunction)
{
	UnitTest* test = new UnitTest(description, unitTestFunction);

	unitTests.push_back(test);
}

int UnitTestSuite::getCount()
{
	return unitTests.size();
}