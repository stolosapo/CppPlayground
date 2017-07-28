#ifndef FunctionTest_h__
#define FunctionTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_function_with_int_apply();
void test_function_with_double_int_apply();
void test_function_with_func_param_int_pointer();
void test_function_with_return_pointer_apply();
void test_function_with_all_pointer_apply();


class FunctionTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FunctionTest();
	virtual ~FunctionTest();

};

#endif // FunctionTest_h__
