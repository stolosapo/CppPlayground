#include <vector>
#include <stdlib.h>
#include <time.h>

#include "KubeSolver.h"
#include "KubeTracer.h"
#include "KubeNavigator.h"

#include "../lib/IKubeSolverWorkflow.h"
#include "../workflow/KubeSolverWorkflowFactory.cpp"

using namespace std;

KubeSolver::KubeSolver(KubeNavigator *navigator)
{
	this->navigator = navigator;
	this->shuffleLevel = KubeSolver::DEFAULT_SUFFLE_LEVEL;
}

KubeSolver::~KubeSolver()
{

}


vector<KubeTracer::Move> getValidMoves()
{
	vector<KubeTracer::Move> moves;

	moves.push_back(KubeTracer::UP);
	moves.push_back(KubeTracer::ANTI_UP);
	moves.push_back(KubeTracer::DOUBLE_UP);
	moves.push_back(KubeTracer::DOWN);
	moves.push_back(KubeTracer::ANTI_DOWN);
	moves.push_back(KubeTracer::DOUBLE_DOWN);
	moves.push_back(KubeTracer::LEFT);
	moves.push_back(KubeTracer::ANTI_LEFT);
	moves.push_back(KubeTracer::DOUBLE_LEFT);
	moves.push_back(KubeTracer::RIGHT);
	moves.push_back(KubeTracer::ANTI_RIGHT );
	moves.push_back(KubeTracer::DOUBLE_RIGHT );
	moves.push_back(KubeTracer::FRONT );
	moves.push_back(KubeTracer::ANTI_FRONT );
	moves.push_back(KubeTracer::DOUBLE_FRONT );
	moves.push_back(KubeTracer::BACK );
	moves.push_back(KubeTracer::ANTI_BACK );
	moves.push_back(KubeTracer::DOUBLE_BACK );
	moves.push_back(KubeTracer::X );
	moves.push_back(KubeTracer::ANTI_X );
	moves.push_back(KubeTracer::DOUBLE_X );
	moves.push_back(KubeTracer::Y );
	moves.push_back(KubeTracer::ANTI_Y );
	moves.push_back(KubeTracer::DOUBLE_Y );

	return moves;
}

void KubeSolver::shuffle()
{
	vector<KubeTracer::Move> registeredMoves;
	registeredMoves = getValidMoves();

	int size = registeredMoves.size();
	int randomIndex;

	/* initialize random seed: */
  	srand(time(NULL));

  	for (int i = 0; i < shuffleLevel; ++i)
  	{
  		/* generate random index between 0 and moves size: */
  		randomIndex = rand() % (size - 1);

  		/* get move */
  		KubeTracer::Move move = registeredMoves[randomIndex];

  		cout << i << ") " << move << endl;

  		/* make the move */
  		navigator->makeTheMove(move);
  	}	

}


void KubeSolver::solve()
{
	IKubeSolverWorkflow *workflow = KubeSolverWorkflowFactory::create();
}