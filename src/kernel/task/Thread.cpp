#include "Thread.h"

#include "ThreadInterceptionData.h"

#include "../converter/Convert.h"
#include "../exception/domain/DomainException.h"
#include "../exception/ExceptionMapper.h"

Thread::Thread()
{
	_thread = 0;

	delegate = NULL;

	id = 0;
	poolIndex = -1;
	dispose = false;
	running = false;
}

Thread::Thread(int poolIndex)
{
    _thread = 0;

	delegate = NULL;

	id = 0;
	this->poolIndex = poolIndex;
	dispose = false;
	running = false;
}

Thread::~Thread()
{
	delegate = NULL;

	if (running)
	{
		cancel();
	}

	wait();
	_thread = 0;

	id = 0;
	dispose = false;
	running = false;
}

void Thread::attachDelegate(ThreadDelegate delegate)
{
	this->delegate = delegate;
}

void Thread::detachDelegate(ThreadDelegate delegate)
{
	this->delegate = NULL;
}

void* Thread::delegateInterceptor(void* interceptionData)
{
	ThreadInterceptionData* interception = (ThreadInterceptionData*) interceptionData;
	ThreadDelegate dlg = interception->getDelegate();
	Thread* th = interception->getThread();

	th->setSelfId();
	th->setMustDispose(true);

	void* retval = NULL;


	try
	{
		th->running = true;
		retval = dlg(interception->getData());
		th->running = false;
	}
	catch(exception& e)
	{
		th->running = false;
		delete interception;
		interception = NULL;

		throw e;
	}

	delete interception;
	interception = NULL;

	return retval;
}

bool Thread::start(void* data)
{
	if (delegate == NULL)
	{
		return false;
	}

	ThreadInterceptionData* interception = new ThreadInterceptionData(this, delegate, data);

	int status = pthread_create(&_thread, NULL, delegateInterceptor, interception);

	return (status == 0);
}

bool Thread::start(void* data, const char* name)
{
    bool status = start(data);

    if (status)
    {
        setName(name);
    }

    return status;
}

void Thread::wait()
{
	if (_thread == 0)
	{
		return;
	}

	pthread_join(_thread, NULL);

	setMustDispose(false);
}

void* Thread::result()
{
	void* retval = NULL;

	if (_thread == 0)
	{
		return retval;
	}

	pthread_join(_thread, &retval);

	setMustDispose(false);

	return retval;
}

bool Thread::cancel()
{
	if (_thread == 0)
	{
		return false;
	}

	int status = pthread_cancel(_thread);

	setMustDispose(false);

	return (status == 0);
}

bool Thread::detach()
{
	if (_thread == 0)
	{
		return false;
	}

	int status = pthread_detach(_thread);

	setMustDispose(false);

	return (status == 0);
}

void* Thread::exit()
{
	void* retval = NULL;

	pthread_exit(retval);

	setMustDispose(false);

	return retval;
}

long long Thread::self()
{
	return pthread_self();
}

void Thread::setName(const char* name)
{
    pthread_setname_np(_thread, name);
}

long long Thread::getId()
{
	return id;
}

int Thread::getPoolIndex()
{
	return poolIndex;
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

bool Thread::isRunning()
{
	return running;
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
