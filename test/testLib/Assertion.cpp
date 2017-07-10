#include "Assertion.h"
#include "AssertException.h"
#include "UnitTest.h"

void assertTrue(bool value)
{
	if (value)
	{
		return;
	}

	string mess = value ? "true" : "false";

	throw AssertException("Exprected " + mess + " to be true");
}

void assertFalse(bool value)
{
	if (!value)
	{
		return;
	}

	string mess = value ? "true" : "false";

	throw AssertException("Exprected " + mess + " to be false");
}

bool assertMethod(string description, UnitTestFunction testFunction)
{
	UnitTest* test = new UnitTest(description, testFunction);

	test->test();

	return test->report();
}
