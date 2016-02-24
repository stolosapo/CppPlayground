#ifndef Kube_h__
#define Kube_h__

#include "KubeSide.h"
#include "../shared/Printable.h"

class Kube : public Printable
{
private:
	static const int SIDE_NUM = 6;

	KubeSide sides[SIDE_NUM];

public:
	Kube();
	virtual ~Kube();

	virtual void print();
};

#endif // Kube_h__