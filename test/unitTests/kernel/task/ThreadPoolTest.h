#ifndef ThreadPoolTest_h__
#define ThreadPoolTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_thread_pool__has_next();
void test_thread_pool__reach_size();
void test_thread_pool__get_next();
void test_thread_pool__get_next__use_queue_pop();
void test_thread_pool__put_back();
void test_thread_pool__multi_threading();


class ThreadPoolTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	ThreadPoolTest();
	virtual ~ThreadPoolTest();

};

#endif // ThreadPoolTest_h__
