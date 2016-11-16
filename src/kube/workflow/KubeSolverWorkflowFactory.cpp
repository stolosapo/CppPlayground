#include "../lib/IKubeSolverWorkflow.h"
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
	
	static IKubeSolverWorkflow *create()
	{
		SolutionWorkflow *workflow = new SolutionWorkflow;

		return (IKubeSolverWorkflow*) workflow;
	}
};