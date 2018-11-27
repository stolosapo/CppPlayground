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
	bool running;

	static void* delegateInterceptor(void *);

	void setId(long long id);
	void setSelfId();
    void setName(const char* name);
	void setMustDispose(bool dispose);

public:
	Thread();
	virtual ~Thread();

	virtual void attachDelegate(ThreadDelegate delegate);
	virtual void detachDelegate(ThreadDelegate delegate);

	virtual bool start(void* data);
    virtual bool start(void* data, const char* name);
	virtual void wait();
	virtual void* result();
	virtual bool cancel();
	virtual bool detach();
	virtual void* exit();

	virtual long long self();

	long long getId();
	string getStringId();
	bool mustDispose();
	bool isRunning();

	Thread& operator+=(ThreadDelegate delegate);
	Thread& operator-=(ThreadDelegate delegate);

};

#endif // Thread_h__
