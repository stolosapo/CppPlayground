#include "TaskRunner.h"

TaskRunner::TaskRunner()
{
        tasks = new Strategy<string, ThreadDelegate>;
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
        tasks->registerStrategy(task, &delegate);
}

Thread* TaskRunner::startTask(string task, void* data)
{
        ThreadDelegate* delegate = tasks->get(task);

        if (delegate == NULL)
        {
                return NULL;
        }

        Thread* th = new Thread;

        th->attachDelegate(*delegate);
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
        ThreadDelegate* delegate = tasks->get(task);

        if (delegate == NULL)
        {
                return NULL;
        }

        ThreadDelegate dlg = *delegate;

        return dlg(data);
}
