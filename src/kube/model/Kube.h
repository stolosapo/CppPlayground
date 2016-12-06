#ifndef Kube_h__
#define Kube_h__

#include <vector>

#include "KubeSide.h"
#include "../action/KubeColorMapper.h"

using namespace std;

class Kube
{
private:
	KubeColorMapper **mapper;

	KubeSide* front;
	KubeSide* right;
	KubeSide* back;
	KubeSide* left;
	KubeSide* upper;
	KubeSide* bottom;	

public:
	Kube();
	virtual ~Kube();

	KubeColorMapper** getColorMapper();

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

	KubeSide::Color getColor(char colorChar);
};

#endif // Kube_h__