#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"
#include "SolutionWorkflow.cpp"

class KubeSolverWorkflowFactory
{
public:
	KubeSolverWorkflowFactory()
	{

	}

	virtual ~KubeSolverWorkflowFactory()
	{

	}
	
	static IKubeSolverWorkflow *create(KubeNavigator* nav)
	{
		SolutionWorkflow *workflow = new SolutionWorkflow(nav);

		return (IKubeSolverWorkflow*) workflow;
	}
};