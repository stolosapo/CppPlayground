#ifndef ThreadInterceptionData_h__
#define ThreadInterceptionData_h__

#include "Thread.h"

class ThreadInterceptionData
{
private:
	Thread* th;
	ThreadDelegate delegate;
	void* data;

public:
	ThreadInterceptionData(Thread* th, ThreadDelegate delegate, void* data);
	virtual ~ThreadInterceptionData();

	virtual Thread* getThread();
	virtual ThreadDelegate getDelegate();
	virtual void* getData();

};

#endif // ThreadInterceptionData_h__
