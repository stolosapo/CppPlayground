#include "PredicateTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/functional/Predicate.h"

PredicateTest::PredicateTest() : UnitTestSuite("Predicate - Test apply", 2)
{

}

PredicateTest::~PredicateTest()
{

}

void PredicateTest::registerTests()
{
	registerCoveredMethod("func");
	registerCoveredMethod("func_pointer");

	registerTest("Predicate with int", &test_predicate_with_int_apply);
	registerTest("Predicate with pointer to int", &test_predicate_with_pointer_apply);
}


bool number_is_one(int a)
{
	return a == 1;
}

bool pointer_is_applied(int* a)
{
	return a[0] == 1;
}


void test_predicate_with_int_apply()
{
	Predicate<int>::func func = number_is_one;

	bool wrong = func(0);
	bool correct = func(1);

	assertFalse(wrong);
	assertTrue(correct);
}

void test_predicate_with_pointer_apply()
{
	Predicate<int>::func_pointer func = pointer_is_applied;

	int* a = new int[1];
	a[0] = 0;

	int* b = new int[1];
	b[0] = 1;

	bool wrong = func(a);
	bool correct = func(b);

	assertFalse(wrong);
	assertTrue(correct);	
}