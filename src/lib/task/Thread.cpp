#include "Thread.h"

#include "../converter/Convert.h"

Thread::Thread()
{
	delegate = NULL;

	id = 0;
}

Thread::~Thread()
{
	delegate = NULL;

	id = 0;
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

long long Thread::self()
{
	return pthread_self();
}

long long Thread::getId()
{
	return id;
}

string Thread::getStringId()
{
	return Convert<long long>::NumberToString(getId());
}

void Thread::setId(long long id)
{
	this->id = id;
}

void Thread::setSelfId()
{
	setId(self());
}

bool Thread::mustDispose()
{
	return dispose;
}

void Thread::setMustDispose(bool dispose)
{
	this->dispose = dispose;
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