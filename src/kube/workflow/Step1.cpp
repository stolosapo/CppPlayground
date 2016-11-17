#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step1 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step1(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 1 - The Cross")
	{

	}

	virtual ~Step1()
	{

	}

	virtual void action()
	{
		cout << "We are in :: " << this->getName() << " stage.. " << endl;
	}

	virtual bool exitCondition()
	{
		return true;
	}

	virtual int retryCount()
	{
		return 3;
	}
	
};