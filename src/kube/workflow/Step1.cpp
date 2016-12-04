#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step1 : public IWorkflowStage<IKubeSolverWorkflow>
{
private:
	Kube* kube;
	KubeNavigator* nav;

	bool isTileCorrectColor(KubeSide::Color tile)
	{
		return kube->getUpper()->getMainColor() == tile;
	}

	bool isTileCorrect(KubeSide::Color tile, KubeSide* side)
	{
		if (!isTileCorrectColor(tile))
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

	}

	virtual int retryCount()
	{
		return 3;
	}

	virtual bool exitCondition()
	{
		KubeSide* side = kube->getUpper();
		KubeSide::Color** tiles = side->getTiles();

		/* 1st row, 2nd tile */
		if (!isTileCorrect(tiles[0][1], kube->getBack()))
		{
			return false;
		}

		/* 2nd row, 1st tile */
		if (!isTileCorrect(tiles[1][0], kube->getLeft()))
		{
			return false;
		}
		
		/* 3nd row, 2nd tile */
		if (!isTileCorrect(tiles[2][1], kube->getFront()))
		{
			return false;
		}

		/* 2nd row, 3rd tile */
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