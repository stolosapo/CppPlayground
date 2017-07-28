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

void assertEqual(int val1, int val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertEqual(long val1, long val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertEqual(long long val1, long long val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertEqual(double val1, double val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertEqual(bool val1, bool val2)
{
	if (val1 == val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}


void assertNotEqual(string val1, string val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected '" + val1 + "' to be equal with '" + val2 + "'");
}

void assertNotEqual(int val1, int val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertNotEqual(long val1, long val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertNotEqual(long long val1, long long val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertNotEqual(double val1, double val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

void assertNotEqual(bool val1, bool val2)
{
	if (val1 != val2)
	{
		return;
	}

	throw AssertException("Exprected 'val1' to be equal with 'val2'");
}

bool assertMethod(string description, UnitTestFunction testFunction)
{
	UnitTest* test = new UnitTest(description, testFunction);

	test->test();

	return test->report();
}
