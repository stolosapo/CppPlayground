#ifndef IWorkflowStage_h__
#define IWorkflowStage_h__

#include <iostream>
#include <string>
#include "IWorkflow.h"

using namespace std;

template<typename T>
class IWorkflowStage
{
private:
	string name;

protected:
	int retryCounter;
	T* workflow;

public:
	IWorkflowStage(T* workflow);
	IWorkflowStage(T* workflow, string name);
	virtual ~IWorkflowStage();

	virtual void beforeAction();
	virtual void action() = 0;
	virtual void afterAction();

	virtual bool exitCondition() = 0;
	virtual int retryCount() = 0;

	int getRetryCounter();
	string getName();
	virtual bool start();

};
















/*********************************
*
*		CONSTRUCTORS
*
**********************************/
template <typename T>
IWorkflowStage<T>::IWorkflowStage(T* workflow)
{
	this->workflow = workflow;
	this->retryCounter = 0;
}

template <typename T>
IWorkflowStage<T>::IWorkflowStage(T* workflow, string name)
{
	this->workflow = workflow;
	this->name = name;
	this->retryCounter = 0;
}

template <typename T>
IWorkflowStage<T>::~IWorkflowStage()
{
	this->workflow = NULL;
}






/*********************************
*
*		PUBLIC METHODS
*
**********************************/

template <typename T>
int IWorkflowStage<T>::getRetryCounter()
{
	return this->retryCounter;
}

template <typename T>
string IWorkflowStage<T>::getName()
{
	return this->name;
}

template <typename T>
void IWorkflowStage<T>::beforeAction()
{

}

template <typename T>
void IWorkflowStage<T>::afterAction()
{
	
}

template <typename T>
bool IWorkflowStage<T>::start()
{
	bool condition = false;
	retryCounter++;

	// First run the before action
	this->beforeAction();

	while (!condition)
	{

		// Run Action
		this->action();

		// Check if Action has true exit condition
		condition = this->exitCondition();

		if (condition)
		{
			break;
		}

		// Increase counter
		retryCounter++;

		// Run stage on not success if exists
		if (retryCounter > retryCount())
		{
			return false;
		}
	}

	// Finally run after action
	this->afterAction();

	return true;
}

#endif // IWorkflowStage_h__