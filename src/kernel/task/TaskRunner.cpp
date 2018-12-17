#include "TaskRunner.h"

#include <iostream>

#include "TaskContext.h"
#include "../utils/StringHelper.h"

using namespace std;

const string TaskRunner::TASK_DELIMITER = "?";
const string TaskRunner::PARAM_DELIMITER = "&";

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

string TaskRunner::getTaskFromParametrizedCommand(string command)
{
    vector<string> params = StringHelper::split(command, TASK_DELIMITER);

    if (params.size() < 1)
    {
        return "";
    }

    return params.at(0);
}

vector<string> TaskRunner::getParamsFromParametrizedCommand(string command)
{
    vector<string> params = StringHelper::split(command, TASK_DELIMITER);

    if (params.size() < 2)
    {
        return vector<string>();
    }

    string paramsStr = params.at(1);

    return StringHelper::split(paramsStr, PARAM_DELIMITER);
}

void TaskRunner::registerTask(string task, ThreadDelegate delegate)
{
    tasks->registerStrategy(task, delegate);
}

bool TaskRunner::taskExist(string task)
{
    return tasks->keyExists(task);
}

bool TaskRunner::parametrizedTaskExist(string task)
{
    return taskExist(getTaskFromParametrizedCommand(task));
}

Thread* TaskRunner::startTask(string task, void* data)
{
    ThreadDelegate delegate = tasks->get(task);

    return startTask(delegate, data);
}

Thread* TaskRunner::startTask(ThreadDelegate delegate, void* data)
{
    if (delegate == NULL)
    {
            return NULL;
    }

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

void* TaskRunner::runParametrizedTask(string task, void* data)
{
    string taskName = getTaskFromParametrizedCommand(task);
    vector<string> params = getParamsFromParametrizedCommand(task);

    ThreadDelegate delegate = tasks->get(taskName);

    if (delegate == NULL)
    {
        return NULL;
    }

    TaskContext* context = new TaskContext(taskName, params, data);

    void* result = delegate(context);

    delete context;

    return result;

}

string TaskRunner::list()
{

}
