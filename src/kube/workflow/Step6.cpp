#include "../lib/IKubeSolverWorkflow.h"
#include "../../kernel/workflow/IWorkflowStage.h"

using namespace std;

class Step6 : public IWorkflowStage<IKubeSolverWorkflow>
{
public:
	Step6(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 6 - The Last Layer Corners 1")
	{

	}

	virtual ~Step6()
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
