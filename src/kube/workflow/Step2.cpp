#include "../lib/IKubeSolverWorkflow.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step2 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step2(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 2 - The Corners")
	{

	}

	virtual ~Step2()
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