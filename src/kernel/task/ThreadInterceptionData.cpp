#include "ThreadInterceptionData.h"

ThreadInterceptionData::ThreadInterceptionData(Thread* th, ThreadDelegate delegate, void* data)
	: th(th), delegate(delegate), data(data)
{

}

ThreadInterceptionData::~ThreadInterceptionData()
{

}

Thread* ThreadInterceptionData::getThread()
{
	return th;
}

ThreadDelegate ThreadInterceptionData::getDelegate()
{
	return delegate;
}

void* ThreadInterceptionData::getData()
{
	return data;
}
