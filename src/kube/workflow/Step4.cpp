#include "../lib/IKubeSolverWorkflow.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step4 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step4(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 4 - The Last Layer Cross")
	{

	}

	virtual ~Step4()
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