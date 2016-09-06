#ifndef KubeSolver_h__
#define KubeSolver_h__

#include "KubeNavigator.h"

class KubeSolver
{
private:
	static const int DEFAULT_SUFFLE_LEVEL = 20;

	KubeNavigator *navigator;

	int shuffleLevel;

public:
	KubeSolver(KubeNavigator *navigator);
	virtual ~KubeSolver();

	void shuffle();
	void solve();
};

#endif // KubeSolver_h__