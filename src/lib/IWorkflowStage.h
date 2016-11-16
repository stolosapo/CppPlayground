#ifndef IWorkflowStage_h__
#define IWorkflowStage_h__

using namespace std;

template<typename T>
class IWorkflowStage
{
private:
	int retryCounter;

protected:
	T* workflow;

public:
	IWorkflowStage(T* workflow);
	virtual ~IWorkflowStage();

	virtual void action() = 0;
	virtual bool exitCondition() = 0;
	virtual int retryCount() = 0;

	int getRetryCounter();
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
void IWorkflowStage<T>::getRetryCounter()
{
	return this->retryCounter;
}

template <typename T>
virtual bool start()
{
	bool success = false;

	bool cond = false;
	retryCounter++;

	while (!success)
	{

		// Run Action
		this->action();

		// Check if Action has true exit condition
		cond = this->exitCondition();

		// Increase counter
		retryCounter++;

		success = !cond && retryCounter < this->retryCount();
	}

	return success;
}

#endif // IWorkflowStage_h__