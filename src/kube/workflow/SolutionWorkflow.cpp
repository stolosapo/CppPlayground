#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"

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

	virtual void start()
	{
		cout << "starteeeeeddddd" << endl;
	}

};