#ifndef Kube_h__
#define Kube_h__

#include "KubeSide.h"

class Kube
{
private:
	KubeSide* front;
	KubeSide* right;
	KubeSide* back;
	KubeSide* left;
	KubeSide* upper;
	KubeSide* bottom;	

public:
	Kube();
	virtual ~Kube();

	KubeSide* getFront();
	KubeSide* getRight();
	KubeSide* getBack();
	KubeSide* getLeft();
	KubeSide* getUpper();
	KubeSide* getBottom();

	void setFront(KubeSide *side);
	void setRight(KubeSide *side);
	void setBack(KubeSide *side);
	void setLeft(KubeSide *side);
	void setUpper(KubeSide *side);
	void setBottom(KubeSide *side);

};

#endif // Kube_h__