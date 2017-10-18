#include "TestTask.h"

#include <iostream>
#include <unistd.h>

using namespace std;

TestTask::TestTask() : AsyncTask()
{
	counter = 0;
}

TestTask::~TestTask()
{

}

void TestTask::task()
{
	cout << "in the task sleepping" << endl;

	counter++;
}