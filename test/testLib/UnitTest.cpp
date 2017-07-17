#include "UnitTest.h"
#include "AssertException.h"
#include "Logger.h"

UnitTest::UnitTest(string description)
{
	this->description = description;
	this->cause = "";
	this->testFunction = NULL;
	this->passed = true;
	this->ignored = false;
}

UnitTest::UnitTest(string description, UnitTestFunction testFunction)
{
	this->description = description;
	this->cause = "";
	this->testFunction = testFunction;
	this->passed = true;
	this->ignored = false;
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

	if (ignored)
	{
		status = "IGNORED";
	}
	else
	{
		if (passed)
		{
			status = "PASSED";
		}
		else
		{
			status = "FAILED";
			extraCause = " - Cause: " + cause;
		}
	}

	string reportMessage = "(" + status + ") - " + description + extraCause + "\n";

	logTestResults(ignored, passed, reportMessage);

	return passed;
}

string UnitTest::getDescription()
{
	return description;
}

bool UnitTest::isPassed()
{
	return passed;
}

bool UnitTest::isIgnored()
{
	return ignored;
}

void UnitTest::setIgnored(bool ignored)
{
	this->ignored = ignored;
}
