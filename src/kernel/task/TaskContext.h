#ifndef TaskContext_h__
#define TaskContext_h__

#include <string>
#include <vector>

using namespace std;

class TaskContext
{
private:
    string task;
    vector<string> params;
    void* data;

public:
	TaskContext(string task, vector<string> params, void* data);
	virtual ~TaskContext();

    string getTask();
    string getParam(int index);
    void* getData();

};

#endif // TaskContext_h__
