#include "../lib/IKubeSolverWorkflow.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step3 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step3(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 3 - The Second Layer")
	{

	}

	virtual ~Step3()
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