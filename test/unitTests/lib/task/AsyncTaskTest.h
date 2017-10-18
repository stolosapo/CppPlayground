#ifndef AsyncTaskTest_h__
#define AsyncTaskTest_h__

#include "../../../testLib/UnitTestSuite.h"


void test_async_task__start_async_with_wait();
void test_async_task__start_async_multiple_times();


class AsyncTaskTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	AsyncTaskTest();
	virtual ~AsyncTaskTest();

};

#endif // AsyncTaskTest_h__
