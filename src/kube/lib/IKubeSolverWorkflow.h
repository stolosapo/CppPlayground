#ifndef IKubeSolverWorkflow_h__
#define IKubeSolverWorkflow_h__

#include "../action/KubeNavigator.h"
#include "../../lib/workflow/IWorkflow.h"

class IKubeSolverWorkflow : public IWorkflow<IKubeSolverWorkflow>
{
protected:
	KubeNavigator *nav;

public:
	IKubeSolverWorkflow(KubeNavigator* nav) : IWorkflow()
	{
		this->nav = nav;
	};

	virtual ~IKubeSolverWorkflow() 
	{
		nav = NULL;
	};

	KubeNavigator* getNavigator()
	{
		return this->nav;
	}
	
};

#endif // IKubeSolverWorkflow_h__