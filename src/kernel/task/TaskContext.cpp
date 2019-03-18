#include "TaskContext.h"

TaskContext::TaskContext(string task, vector<string> params, void* data)
    : task(task), params(params), data(data)
{

}

TaskContext::~TaskContext()
{

}

string TaskContext::getTask()
{
    return task;
}

string TaskContext::getParam(int index)
{
    if (index >= params.size())
    {
        return "";
    }

    return params.at(index);
}

void* TaskContext::getData()
{
    return data;
}
