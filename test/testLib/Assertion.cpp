#include "Assertion.h"
#include "AssertException.h"
#include "UnitTest.h"

#include <stdio.h>

void assertTrue(bool value)
{
	if (value)
	{
		return;
	}

	string strValue = value ? "true" : "false";

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be true", strValue);

	throw AssertException(mess);
}

void assertFalse(bool value)
{
	if (!value)
	{
		return;
	}

	string strValue = value ? "true" : "false";

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be false", strValue);

	throw AssertException(mess);
}


void assertEqual(string val1, string val2)
{
	if (val1 == val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be equal with '%s'", val1, val2);

	throw AssertException(mess);
}

void assertEqual(int val1, int val2)
{
	if (val1 == val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%d' to be equal with '%d'", val1, val2);

	throw AssertException(mess);
}

void assertEqual(long val1, long val2)
{
	if (val1 == val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%ld' to be equal with '%ld'", val1, val2);

	throw AssertException(mess);
}

void assertEqual(long long val1, long long val2)
{
	if (val1 == val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%lld' to be equal with '%lld'", val1, val2);

	throw AssertException(mess);
}

void assertEqual(double val1, double val2)
{
	if (val1 == val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%lf' to be equal with '%lf'", val1, val2);

	throw AssertException(mess);
}

void assertEqual(bool val1, bool val2)
{
	if (val1 == val2)
	{
		return;
	}

	string strVal1 = val1 ? "true" : "false";
	string strVal2 = val2 ? "true" : "false";

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be equal with '%s'", strVal1, strVal2);

	throw AssertException(mess);
}


void assertNotEqual(string val1, string val2)
{
	if (val1 != val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be equal with '%s'", val1, val2);

	throw AssertException(mess);
}

void assertNotEqual(int val1, int val2)
{
	if (val1 != val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%d' to be equal with '%d'", val1, val2);

	throw AssertException(mess);
}

void assertNotEqual(long val1, long val2)
{
	if (val1 != val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%ld' to be equal with '%ld'", val1, val2);

	throw AssertException(mess);
}

void assertNotEqual(long long val1, long long val2)
{
	if (val1 != val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%lld' to be equal with '%lld'", val1, val2);

	throw AssertException(mess);
}

void assertNotEqual(double val1, double val2)
{
	if (val1 != val2)
	{
		return;
	}

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%lf' to be equal with '%lf'", val1, val2);

	throw AssertException(mess);
}

void assertNotEqual(bool val1, bool val2)
{
	if (val1 != val2)
	{
		return;
	}

	string strVal1 = val1 ? "true" : "false";
	string strVal2 = val2 ? "true" : "false";

	char* mess = new char[1024];

	sprintf(mess, "Exprected '%s' to be equal with '%s'", strVal1, strVal2);

	throw AssertException(mess);
}

bool assertMethod(string description, UnitTestFunction testFunction)
{
	UnitTest* test = new UnitTest(description, testFunction);

	test->test();

	return test->report();
}
