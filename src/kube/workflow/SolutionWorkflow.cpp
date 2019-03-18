#include "../../kernel/workflow/IWorkflow.h"
#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"

#include "Step1.cpp"
#include "Step2.cpp"
#include "Step3.cpp"
#include "Step4.cpp"
#include "Step5.cpp"
#include "Step6.cpp"
#include "Step7.cpp"

using namespace std;

class SolutionWorkflow : public IKubeSolverWorkflow
{
public:
	SolutionWorkflow(KubeNavigator* nav) : IKubeSolverWorkflow(nav)
	{

	}

	virtual ~SolutionWorkflow()
	{

	}

	virtual void registerStages()
	{
		stages.push_back(new Step1(this));
		stages.push_back(new Step2(this));
		stages.push_back(new Step3(this));
		stages.push_back(new Step4(this));
		stages.push_back(new Step5(this));
		stages.push_back(new Step6(this));
		stages.push_back(new Step7(this));
	}

};
