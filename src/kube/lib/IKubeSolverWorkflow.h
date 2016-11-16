#ifndef IKubeSolverWorkflow_h__
#define IKubeSolverWorkflow_h__

#include "../action/KubeNavigator.h"

class IKubeSolverWorkflow
{
protected:
	KubeNavigator *nav;

public:
	IKubeSolverWorkflow(KubeNavigator* nav) 
	{
		this->nav = nav;
	};

	virtual ~IKubeSolverWorkflow() 
	{
		nav = NULL;
	};

	virtual void start() = 0;
};

#endif // IKubeSolverWorkflow_h__