#include "../lib/IKubeSolverWorkflow.h"
#include "../../kernel/workflow/IWorkflowStage.h"

using namespace std;

class Step7 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step7(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 7 - The Last Layer Corners 2")
	{

	}

	virtual ~Step7()
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
