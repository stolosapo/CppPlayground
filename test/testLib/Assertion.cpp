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

void assertEqual(string val1, string val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected '" + val1 + "' to be equal with '" + val2 + "'");
}

bool assertMethod(string description, UnitTestFunction testFunction)
{
	UnitTest* test = new UnitTest(description, testFunction);

	test->test();

	return test->report();
}
