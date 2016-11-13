#ifndef KubeNavigator_h__
#define KubeNavigator_h__

#include "Kube.h"
#include "KubeTracer.h"
#include "KubePrinter.h"

/**
 *  Based on this https://solvethecube.com/notation
 */
class KubeNavigator
{
private:
	Kube *kube;
	KubeTracer *tracer;
	KubePrinter *printer;

	bool useTracer;
	bool printMove;
	bool doubleMove;

	typedef void (KubeNavigator::*moveMethod)();

	int reverseIndex(int index);

	void moveHorizontial(bool clockwise, bool straight, int row);
	
	void moveVerticalX(bool clockwise, bool straight, int col);
	void moveVerticalZ(bool clockwise, bool straight, int row, int col);

	void moveFace(bool clockwise, bool straight, KubeSide *faceSide);
	void moveDouble(moveMethod method);

	void traceMove(KubeTracer::Move move);

public:
	KubeNavigator(Kube *kube);
	KubeNavigator(Kube *kube, KubeTracer *tracer);
	virtual ~KubeNavigator();

	void setPrinter(KubePrinter *printer);
	void setPrintMove(bool printMove);

	void makeTheMove(KubeTracer::Move move);
	
	void up();
	void aUp();
	void up2();

	void down();
	void aDown();
	void down2();

	void left();
	void aLeft();
	void left2();

	void right();
	void aRight();
	void right2();
	
	void front();
	void aFront();
	void front2();

	void back();
	void aBack();
	void back2();



	void moveX();
	void moveAx();
	void moveX2();

	void moveY();
	void moveAy();
	void moveY2();

	void moveZ();
	void moveAz();
	void moveZ2();	

};

#endif // KubeNavigator_h__