#include "ConsumerTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/functional/Consumer.h"

ConsumerTest::ConsumerTest() : UnitTestSuite("Consumer - Test apply", 2)
{

}

ConsumerTest::~ConsumerTest()
{

}

void ConsumerTest::registerTests()
{
	registerCoveredMethod("func");
	registerCoveredMethod("func_pointer");

	registerTest("Consumer with int", &test_consumer_with_int_param);
	registerTest("Consumer with pointer to int", &test_consumer_with_pointer_param);
}


void consumer_int_param(int a)
{
        // Do something
        int b = a * a;
}

void consumer_return_int_pointer(int* a)
{
        a[0] = 1;
}


void test_consumer_with_int_param()
{
	Consumer<int>::func func = consumer_int_param;

        func(0);

        assertTrue(true);
}

void test_consumer_with_pointer_param()
{
	Consumer<int>::func_pointer func = consumer_return_int_pointer;

        int* a = new int[1];

        func(a);

        assertEqual(a[0], 1);
	assertNotEqual(a[0], 0);
}
