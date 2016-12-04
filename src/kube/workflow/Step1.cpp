#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step1 : public IWorkflowStage<IKubeSolverWorkflow>
{
private:
	Kube* kube;
	KubeNavigator* nav;

	bool isTileCorrect(KubeSide::Color tile, KubeSide* side)
	{
		KubeSide::Color mainColor = kube->getUpper()->getMainColor();

		if (tile != mainColor)
		{
			return false;
		}

		return side->getMainColor() == side->getTiles()[0][1];
	}

public:
	Step1(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 1 - The Cross")
	{
		this->nav = workflow->getNavigator();
		this->kube = nav->getKube();
	}

	virtual ~Step1()
	{
		this->kube = NULL;
		this->nav = NULL;
	}

	virtual int retryCount()
	{
		return 3;
	}

	virtual bool exitCondition()
	{
		KubeSide* side = kube->getUpper();
		KubeSide::Color** tiles = side->getTiles();

		if (!isTileCorrect(tiles[0][1], kube->getBack()))
		{
			return false;
		}

		if (!isTileCorrect(tiles[1][0], kube->getLeft()))
		{
			return false;
		}
		
		if (!isTileCorrect(tiles[2][1], kube->getFront()))
		{
			return false;
		}

		if (!isTileCorrect(tiles[1][2], kube->getFront()))
		{
			return false;
		}

		return true;
	}

	virtual void beforeAction()
	{
		nav->moveX();
	}

	virtual void action()
	{
		cout << "We are in :: " << this->getName() << " stage.. " << endl;
	}
	
};