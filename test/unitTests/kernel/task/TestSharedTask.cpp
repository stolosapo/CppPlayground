#include "TestSharedTask.h"

#include <iostream>
#include <unistd.h>

using namespace std;

TestSharedTask::TestSharedTask(int* counter) : AsyncTask(), counter(*counter)
{

}

TestSharedTask::~TestSharedTask()
{

}

void* TestSharedTask::task()
{
	counter++;
}
