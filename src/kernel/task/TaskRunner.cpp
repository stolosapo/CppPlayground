#include "TaskRunner.h"

#include <iostream>

using namespace std;

TaskRunner::TaskRunner()
{
        tasks = new ValueStrategy<string, ThreadDelegate>;
}

TaskRunner::~TaskRunner()
{
        if (tasks != NULL)
        {
                delete tasks;
        }
}

void TaskRunner::registerTask(string task, ThreadDelegate delegate)
{
        tasks->registerStrategy(task, delegate);
}

bool TaskRunner::taskExist(string task)
{
        return tasks->keyExists(task);
}

Thread* TaskRunner::startTask(string task, void* data)
{
        ThreadDelegate delegate = tasks->get(task);

        if (delegate == NULL)
        {
                return NULL;
        }

        cout << delegate;

        Thread* th = new Thread;

        th->attachDelegate(delegate);
        th->start(data);

        return th;
}

void TaskRunner::startTaskDetached(string task, void* data)
{
        Thread* th = startTask(task, data);

        th->detach();
}

void* TaskRunner::runTask(string task, void* data)
{
        ThreadDelegate delegate = tasks->get(task);

        if (delegate == NULL)
        {
                return NULL;
        }

        return delegate(data);
}
