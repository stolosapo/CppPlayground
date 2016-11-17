#ifndef IWorkflow_h__
#define IWorkflow_h__

#include <vector>
#include "IWorkflowStage.h"

using namespace std;

template<typename T>
class IWorkflow
{
protected:
	vector< IWorkflowStage<T>* > stages;

public:
	IWorkflow();
	virtual ~IWorkflow();

	virtual void registerStages() = 0;
	virtual bool start();
	
};
















/*********************************
*
*		CONSTRUCTORS
*
**********************************/
template <typename T>
IWorkflow<T>::IWorkflow()
{
	
}

template <typename T>
IWorkflow<T>::~IWorkflow()
{
	for (int i = 0; i < stages.size(); ++i)
	{
		stages[i] = NULL;
	}

	stages.clear();
}






/*********************************
*
*		PUBLIC METHODS
*
**********************************/
template <typename T>
bool IWorkflow<T>::start()
{
	for (int i = 0; i < stages.size(); ++i)
	{
		IWorkflowStage<T>* stage = stages[i];

		if (!stage->start())
		{
			return false;
		}
	}

	return true;
}

#endif // IWorkflow_h__