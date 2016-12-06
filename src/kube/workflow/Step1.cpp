#include <vector>

#include "../lib/IKubeSolverWorkflow.h"
#include "../action/KubeNavigator.h"
#include "../../lib/workflow/IWorkflowStage.h"

using namespace std;

class Step1 : public IWorkflowStage<IKubeSolverWorkflow>
{
private:
	Kube* kube;
	KubeNavigator* nav;

	vector<KubeSide*> sides;

	vector<KubeSide*> getSides()
	{
		vector<KubeSide*> s;

		s.push_back(kube->getUpper());
		s.push_back(kube->getFront());
		s.push_back(kube->getRight());
		s.push_back(kube->getLeft());
		s.push_back(kube->getBack());
		s.push_back(kube->getBottom());

		return s;
	}

	KubeSide::Color mainColor()
	{
		return kube->getUpper()->getMainColor();
	}

	bool isTileCorrectColor(KubeSide::Color tile)
	{
		return mainColor() == tile;
	}

	bool isTileCorrect(KubeSide::Color tile, KubeSide* side)
	{
		if (!isTileCorrectColor(tile))
		{
			return false;
		}

		return side->getMainColor() == side->getTiles()[0][1];
	}

	KubeSide::Color upperTile(KubeSide* side)
	{
		return side->getTiles()[0][1];
	}

	KubeSide::Color leftTile(KubeSide* side)
	{
		return side->getTiles()[1][0];
	}

	KubeSide::Color bottomTile(KubeSide* side)
	{
		return side->getTiles()[2][1];
	}

	KubeSide::Color rightTile(KubeSide* side)
	{
		return side->getTiles()[1][2];
	}

	bool mainColorInSideExists(KubeSide* side)
	{
		if (isTileCorrectColor(upperTile(side)))
		{
			return true;
		}

		if (isTileCorrectColor(leftTile(side)))
		{
			return true;
		}

		if (isTileCorrectColor(bottomTile(side)))
		{
			return true;
		}

		if (isTileCorrectColor(rightTile(side)))
		{
			return true;
		}

		return false;
	}

	bool isUpperSide(KubeSide* side)
	{
		return side->getMainColor() == KubeSide::MAIN_UP;
	}

	bool isFaceSide(KubeSide* side)
	{
		return side->getMainColor() == KubeSide::MAIN_RIGHT ||
				side->getMainColor() == KubeSide::MAIN_LEFT ||
				side->getMainColor() == KubeSide::MAIN_BACK;
	}

	bool isBottomSide(KubeSide* side)
	{
		return side->getMainColor() == KubeSide::MAIN_DOWN;
	}	

	bool proccedUpperSide(KubeSide* side)
	{
		cout << "Procced in upper side " << endl;

		/* if is the upper cross tile */
		if (isTileCorrectColor(upperTile(side)))
		{
			cout << "in upper cross tile " << endl;
			// nav->back2();
		}

		/* if is the left cross tile */
		if (isTileCorrectColor(leftTile(side)))
		{
			cout << "in left cross tile " << endl;
			// nav->left2();
		}

		/* if is the bottom cross tile */
		if (isTileCorrectColor(bottomTile(side)))
		{
			cout << "in bottom cross tile " << endl;
			// nav->front2();
		}

		/* if is the right cross tile */
		if (isTileCorrectColor(rightTile(side)))
		{
			cout << "in right cross tile " << endl;
			// nav->right2();
		}

		return false;
	}

	bool proccedFaceSide(KubeSide* side)
	{
		cout << "Procced in face side " << endl;
		return false;
	}

	bool proccedBottomSide(KubeSide* side)
	{
		cout << "Procced in bottom side " << endl;
		return false;
	}

	bool proccedSide(KubeSide* side)
	{
		if (isUpperSide(side))
		{
			return proccedUpperSide(side);
		}

		if (isFaceSide(side))
		{
			return proccedFaceSide(side);
		}

		if (isBottomSide(side))
		{
			return proccedBottomSide(side);
		}

		return false;
	}

public:
	Step1(IKubeSolverWorkflow* workflow) : IWorkflowStage(workflow, "Step 1 - The Cross")
	{
		this->nav = workflow->getNavigator();
		this->kube = nav->getKube();
		this->sides = getSides();
	}

	virtual ~Step1()
	{
		vector<KubeSide*>().swap(this->sides);
	}

	virtual int retryCount()
	{
		return 1;
	}

	virtual bool exitCondition()
	{
		/* 1st row, 2nd tile */
		if (!isTileCorrect(upperTile(kube->getUpper()), kube->getBack()))
		{
			return false;
		}

		/* 2nd row, 1st tile */
		if (!isTileCorrect(leftTile(kube->getUpper()), kube->getLeft()))
		{
			return false;
		}
		
		/* 3nd row, 2nd tile */
		if (!isTileCorrect(bottomTile(kube->getUpper()), kube->getFront()))
		{
			return false;
		}

		/* 2nd row, 3rd tile */
		if (!isTileCorrect(rightTile(kube->getUpper()), kube->getFront()))
		{
			return false;
		}

		return true;
	}

	virtual void beforeAction()
	{
		cout << "Main Color before move " << mainColor() << endl;
		nav->moveX();
		cout << "Main Color after move " << mainColor() << endl;
	}

	virtual void action()
	{
		cout << "We are in :: " << this->getName() << " stage.. " << endl;

		bool foundMove = true;
		while (foundMove)
		{
			for (int i = 0; i < sides.size(); ++i)
			{
				if (mainColorInSideExists(sides[i]))
				{
					/* procced side */
					foundMove = proccedSide(sides[i]);

					/* if some move done then start from begin */
					if (foundMove)
					{
						break;
					}
				}
			}
		}

	}
	
};