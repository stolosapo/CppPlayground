#ifndef TestSharedTask_h__
#define TestSharedTask_h__


#include "../../../../src/lib/task/AsyncTask.h"


class TestSharedTask: public AsyncTask
{
protected:
	void* task();

public:
	int& counter;

	TestSharedTask(int* counter);
	virtual ~TestSharedTask();

};

#endif // TestSharedTask_h__
