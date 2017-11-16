#include "Thread.h"

Thread::Thread()
{
	delegate = NULL;
}

Thread::~Thread()
{
	delegate = NULL;
}

void Thread::attachDelegate(ThreadDelegate delegate)
{
	this->delegate = delegate;
}

void Thread::detachDelegate(ThreadDelegate delegate)
{
	this->delegate = NULL;
}

bool Thread::start(void* data)
{
	if (delegate == NULL)
	{
		return false;
	}

	int status = pthread_create(&_thread, NULL, delegate, data);

	return (status == 0);
}

void Thread::wait()
{
        pthread_join(_thread, NULL);
}

Thread& Thread::operator+=(ThreadDelegate delegate)
{
	attachDelegate(delegate);
	return *this;
}

Thread& Thread::operator-=(ThreadDelegate delegate)
{
	detachDelegate(delegate);
	return *this;
}