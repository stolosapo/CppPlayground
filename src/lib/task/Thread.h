#ifndef Thread_h__
#define Thread_h__

#include <pthread.h>
#include "ThreadDelegate.h"

class Thread
{
private:
	pthread_t _thread;

	ThreadDelegate delegate;

public:
	Thread();
	virtual ~Thread();

	virtual void attachDelegate(ThreadDelegate delegate);
	virtual void detachDelegate(ThreadDelegate delegate);

        virtual bool start(void* data);
        virtual void wait();

        Thread& operator+=(ThreadDelegate delegate);
        Thread& operator-=(ThreadDelegate delegate);

};

#endif // Thread_h__
