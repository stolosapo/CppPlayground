#include "../lib/IKubeSolverWorkflow.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step5 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step5(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 5 - The Last Layer Edges")
	{

	}

	virtual ~Step5()
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