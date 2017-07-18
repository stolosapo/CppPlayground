#include "FunctionTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/lib/functional/Function.h"


FunctionTest::FunctionTest() : UnitTestSuite("Function - Test apply", 4)
{

}

FunctionTest::~FunctionTest()
{

}

void FunctionTest::registerTests()
{
	registerCoveredMethod("func");
	registerCoveredMethod("func_param_pointer");
	// registerCoveredMethod("func_return_pointers");
	// registerCoveredMethod("func_all_pointers");

	registerTest("Function with int", &test_function_with_int_apply);
	registerTest("Function with int to double", &test_function_with_double_int_apply);
	registerTest("Function with param int pointer to int", &test_function_with_func_param_int_pointer);
}


int all_ints(int a)
{
	return a + 1;
}

double double_int(int a)
{
	return (a * 33.33);
}

int func_param_int_pointer(int* a)
{
	return a[0];
}


void test_function_with_int_apply()
{
	Function<int, int>::func func = all_ints;

	assertEqual(func(0), 1);
	assertEqual(func(1), 2);
	assertNotEqual(func(2), 2);
}

void test_function_with_double_int_apply()
{
	Function<int, double>::func func = double_int;

	assertEqual(func(0), 0.0);
	assertEqual(func(1), 33.33);
	assertNotEqual(func(2), 33.33);
}

void test_function_with_func_param_int_pointer()
{
	Function<int, int>::func_param_pointer func = func_param_int_pointer;

	int* a = new int[1];
	a[0] = 0;

	int* b = new int[1];
	b[0] = 1;

	assertEqual(func(a), 0);
	assertEqual(func(b), 1);
	assertNotEqual(func(b), 0);
}
