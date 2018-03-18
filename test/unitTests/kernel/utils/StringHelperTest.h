#ifndef StringHelperTest_h__
#define StringHelperTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_split_return_correct_result_count();
void test_split_return_correct_results();

class StringHelperTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	StringHelperTest();
	virtual ~StringHelperTest();

};

#endif // StringHelperTest_h__
