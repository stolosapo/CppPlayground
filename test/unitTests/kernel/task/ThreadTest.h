#ifndef ThreadTest_h__
#define ThreadTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_thread__start_with_wait();


class ThreadTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	ThreadTest();
	virtual ~ThreadTest();

};

#endif // ThreadTest_h__
