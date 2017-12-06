#ifndef Thread_h__
#define Thread_h__

#include <string>
#include <pthread.h>
#include "ThreadDelegate.h"

using namespace std;

class Thread
{
private:
	pthread_t _thread;

	ThreadDelegate delegate;

	long long id;
	bool dispose;

public:
	Thread();
	virtual ~Thread();

	virtual void attachDelegate(ThreadDelegate delegate);
	virtual void detachDelegate(ThreadDelegate delegate);

	virtual bool start(void* data);
	virtual void wait();
	virtual long long self();

	long long getId();
	string getStringId();
	void setId(long long id);
	void setSelfId();

	bool mustDispose();
	void setMustDispose(bool dispose);

	Thread& operator+=(ThreadDelegate delegate);
	Thread& operator-=(ThreadDelegate delegate);

};

#endif // Thread_h__
