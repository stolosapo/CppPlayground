#ifndef SupplierTest_h__
#define SupplierTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_supplier_with_int_return();
void test_supplier_with_pointer_return();


class SupplierTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	SupplierTest();
	virtual ~SupplierTest();

};

#endif // SupplierTest_h__
