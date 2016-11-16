#ifndef IWorkflow_h__
#define IWorkflow_h__

#include <vector.h>
#include "IWorkflowStage.h"

using namespace std;

template<typename T>
class IWorkflow
{
protected:
	vector<IWorkflowStage<T>> stages;

public:
	IWorkflow();
	virtual ~IWorkflow();

	virtual void registerStages();
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

}






/*********************************
*
*		PUBLIC METHODS
*
**********************************/

template <typename T>
void IWorkflow<T>::registerStages()
{
	
}

template <typename T>
bool IWorkflow<T>::start()
{
	
}

#endif // IWorkflow_h__