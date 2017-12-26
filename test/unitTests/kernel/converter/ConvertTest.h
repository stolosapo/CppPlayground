#ifndef ConvertTest_h__
#define ConvertTest_h__

#include <iostream>

#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_convert_int_to_string();
void test_convert_long_to_string();
void test_convert_long_long_to_string();
void test_convert_double_to_string();
void test_convert_string_to_int();
void test_convert_string_to_long();
void test_convert_string_to_long_long();
void test_convert_string_to_double();

class ConvertTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	ConvertTest();
	virtual ~ConvertTest();

};

#endif // ConvertTest_h__
