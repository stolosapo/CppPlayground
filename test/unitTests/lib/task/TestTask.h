#ifndef TestTask_h__
#define TestTask_h__


#include "../../../../src/lib/task/AsyncTask.h"


class TestTask: public AsyncTask
{
protected:
	void task();

public:
	int counter;

	TestTask();
	virtual ~TestTask();

};

#endif // TestTask_h__
