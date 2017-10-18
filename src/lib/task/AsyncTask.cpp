#include "AsyncTask.h"

AsyncTask::AsyncTask()
{

}

AsyncTask::~AsyncTask()
{

}

void* AsyncTask::internalThreadFunc(void* self)
{
	((AsyncTask *)self)->task(); 

	return NULL;
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