#include "AsyncTask.h"

AsyncTask::AsyncTask()
{

}

AsyncTask::~AsyncTask()
{

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
