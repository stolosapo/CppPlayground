#include "AsyncTask.h"

AsyncTask::AsyncTask()
{
	pthread_mutex_init(&_mutex, 0);
}

AsyncTask::~AsyncTask()
{
	pthread_mutex_destroy(&_mutex);
}

void* AsyncTask::internalThreadFunc(void* self)
{
	return ((AsyncTask *)self)->task();
}

bool AsyncTask::startAsync()
{
        int status = pthread_create(&_thread, NULL, AsyncTask::internalThreadFunc, this);

	return (status == 0);
}

void AsyncTask::waitToExit()
{
        (void) pthread_join(_thread, NULL);
}

void AsyncTask::selfLock()
{
	pthread_mutex_lock(&_mutex);
}

void AsyncTask::selfUnlock()
{
	pthread_mutex_unlock(&_mutex);
}
