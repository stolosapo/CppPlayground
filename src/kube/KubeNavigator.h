#ifndef KubeNavigator_h__
#define KubeNavigator_h__

#include "Kube.h"

class KubeNavigator
{
private:
	Kube *kube;

public:
	KubeNavigator(Kube *kube);
	virtual ~KubeNavigator();

	void front();
	void back();
	void up();
	void left();
	void right();

	void moveX();
	void moveY();
	void moveZ();

	void aFront();
	void aBack();
	void aUp();
	void aLeft();
	void aRight();

	void moveAx();
	void moveAy();
	void moveAz();
};

#endif // KubeNavigator_h__