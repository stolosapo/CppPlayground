#ifndef TaskRunner_h__
#define TaskRunner_h__

#include <string>
#include "Thread.h"
#include "ThreadDelegate.h"
#include "../strategy/Strategy.h"

using namespace std;

class TaskRunner
{
private:
        Strategy<string, ThreadDelegate> *tasks;

public:
	TaskRunner();
	virtual ~TaskRunner();

        virtual void registerTask(string task, ThreadDelegate delegate);

        virtual Thread* startTask(string task, void* data);
        virtual void startTaskDetached(string task, void* data);
        virtual void* runTask(string task, void* data);
};

#endif // TaskRunner_h__