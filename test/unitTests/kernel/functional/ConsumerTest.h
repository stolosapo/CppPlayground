#ifndef ConsumerTest_h__
#define ConsumerTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_consumer_with_int_param();
void test_consumer_with_pointer_param();


class ConsumerTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	ConsumerTest();
	virtual ~ConsumerTest();

};

#endif // ConsumerTest_h__
