#include "UnitTest.h"
#include "AssertException.h"
#include "Logger.h"

UnitTest::UnitTest(string description, UnitTestFunction testFunction)
{
	this->description = description;
	this->cause = cause;
	this->testFunction = testFunction;
	this->passed = true;
}

UnitTest::~UnitTest()
{

}

void UnitTest::test()
{
	try
	{
		if (this->testFunction == NULL)
		{
			return;
		}

		(testFunction)();
	}
	catch (int e)
	{
		this->passed = false;
	}
	catch (AssertException& e)
	{
		this->cause = e.what();
		this->passed = false;
	}
	catch (exception& e)
	{
		this->cause = e.what();
		this->passed = false;
	}
}

bool UnitTest::report()
{
	string status;
	string extraCause = "";

	if (passed)
	{
		status = "PASSED";
	}
	else
	{
		status = "FAILED";
		extraCause = " - Cause: " + cause;
	}

	string reportMessage = "(" + status + ") - " + description + extraCause + "\n";

	logTestResults(passed, reportMessage);

	return passed;
}
