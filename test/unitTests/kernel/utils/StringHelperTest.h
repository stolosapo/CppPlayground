#ifndef StringHelperTest_h__
#define StringHelperTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_split_return_correct_result_count();
void test_split_return_correct_results();

void test__pad__return_correct_result__possitive();
void test__pad__return_correct_result__zero();
void test__pad__return_correct_result__negative();

void test__removeStart__return_correct_result__string_exist();
void test__removeStart__return_correct_result__string_not_exist();
void test__removeStart__return_correct_result__string_is_empty();

class StringHelperTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	StringHelperTest();
	virtual ~StringHelperTest();

};

#endif // StringHelperTest_h__
