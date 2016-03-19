#ifndef KubeNavigator_h__
#define KubeNavigator_h__

#include "Kube.h"

class KubeNavigator
{
private:
	Kube *kube;

	void moveHorizontial(bool clockwise, bool straight, int row);
	void moveVertical(bool clockwise, bool straight, int col);
	void moveFace(bool clockwise, bool straight, KubeSide *faceSide);

public:
	KubeNavigator(Kube *kube);
	virtual ~KubeNavigator();

	void front();
	void back();
	void up();
	void down();
	void left();
	void right();

	void moveX();
	void moveY();
	void moveZ();

	void aFront();
	void aBack();
	void aUp();
	void aDown();
	void aLeft();
	void aRight();

	void moveAx();
	void moveAy();
	void moveAz();
};

#endif // KubeNavigator_h__