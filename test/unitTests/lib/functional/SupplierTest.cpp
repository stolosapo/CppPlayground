#include "SupplierTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/lib/functional/Supplier.h"

SupplierTest::SupplierTest() : UnitTestSuite("Supplier - Test apply", 2)
{

}

SupplierTest::~SupplierTest()
{

}

void SupplierTest::registerTests()
{
	registerCoveredMethod("func");
	registerCoveredMethod("func_pointer");

	registerTest("Supplier with int", &test_supplier_with_int_return);
	registerTest("Supplier with pointer to int", &test_supplier_with_pointer_return);
}


int supplier_return_int()
{
	return 1;
}

int* supplier_return_int_pointer()
{
        int* a = new int[1];
        a[0] = 1;

	return a;
}


void test_supplier_with_int_return()
{
	Supplier<int>::func func = supplier_return_int;

	assertEqual(func(), 1);
        assertNotEqual(func(), 2);
}

void test_supplier_with_pointer_return()
{
	Supplier<int>::func_pointer func = supplier_return_int_pointer;

        assertEqual(func()[0], 1);
	assertNotEqual(func()[0], 0);
}
