#include <iostream>
#include "KubeNavigator.h"

using namespace std;

KubeNavigator::KubeNavigator(Kube *kube)
{
	this->kube = kube;
	this->tracer = NULL;
	this->useTracer = false;
	this->printMove = false;
	this->doubleMove = false;
}

KubeNavigator::KubeNavigator(Kube *kube, KubeTracer *tracer)
{
	this->kube = kube;
	this->tracer = tracer;
	this->useTracer = true;
	this->printMove = false;
	this->doubleMove = false;
}

KubeNavigator::KubeNavigator(Kube *kube, KubeTracer *tracer, KubePrinter *printer)
{
	this->kube = kube;
	this->tracer = tracer;
	this->printer = printer;
	this->useTracer = true;
	this->printMove = false;
	this->doubleMove = false;
}

KubeNavigator::~KubeNavigator()
{

}

void KubeNavigator::setPrinter(KubePrinter *printer)
{
	this->printer = printer;
}

void KubeNavigator::setPrintMove(bool printMove)
{
	this->printMove = printMove;
}

int KubeNavigator::reverseIndex(int index)
{
	if (index == 0)
	{
		return 2;
	}
	else if (index == 2)
	{
		return 0;
	}

	return index;
}

void KubeNavigator::moveHorizontial(bool clockwise, bool straight, int row)
{
	KubeSide *nextSide;
	KubeSide *prevSide;

	/* First Side row Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getFront()->getTiles()[row][0];
	buffer[1] = kube->getFront()->getTiles()[row][1];
	buffer[2] = kube->getFront()->getTiles()[row][2];

	if (!(clockwise ^ straight))
	{
		nextSide = kube->getRight();
		prevSide = kube->getLeft();
	}
	else
	{
		nextSide = kube->getLeft();
		prevSide = kube->getRight();
	}

	/* Front Side */
	kube->getFront()->getTiles()[row][0] = nextSide->getTiles()[row][0];
	kube->getFront()->getTiles()[row][1] = nextSide->getTiles()[row][1];
	kube->getFront()->getTiles()[row][2] = nextSide->getTiles()[row][2];

	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[row][0] = kube->getBack()->getTiles()[row][0];
	nextSide->getTiles()[row][1] = kube->getBack()->getTiles()[row][1];
	nextSide->getTiles()[row][2] = kube->getBack()->getTiles()[row][2];

	/* Back Side */
	kube->getBack()->getTiles()[row][0] = prevSide->getTiles()[row][0];
	kube->getBack()->getTiles()[row][1] = prevSide->getTiles()[row][1];
	kube->getBack()->getTiles()[row][2] = prevSide->getTiles()[row][2];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[row][0] = buffer[0];
	prevSide->getTiles()[row][1] = buffer[1];
	prevSide->getTiles()[row][2] = buffer[2];
}

void KubeNavigator::moveVerticalX(bool clockwise, bool straight, int col)
{
	KubeSide *nextSide;
	KubeSide *prevSide;

	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getFront()->getTiles()[0][col];
	buffer[1] = kube->getFront()->getTiles()[1][col];
	buffer[2] = kube->getFront()->getTiles()[2][col];

	if (clockwise ^ straight)
	{
		nextSide = kube->getUpper();
		prevSide = kube->getBottom();
	}
	else
	{
		nextSide = kube->getBottom();
		prevSide = kube->getUpper();
	}

	/* Front Side */
	kube->getFront()->getTiles()[0][col] = nextSide->getTiles()[0][col];
	kube->getFront()->getTiles()[1][col] = nextSide->getTiles()[1][col];
	kube->getFront()->getTiles()[2][col] = nextSide->getTiles()[2][col];

	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][col] = kube->getBack()->getTiles()[reverseIndex(0)][reverseIndex(col)];
	nextSide->getTiles()[1][col] = kube->getBack()->getTiles()[reverseIndex(1)][reverseIndex(col)];
	nextSide->getTiles()[2][col] = kube->getBack()->getTiles()[reverseIndex(2)][reverseIndex(col)];

	/* Back Side */
	kube->getBack()->getTiles()[reverseIndex(0)][reverseIndex(col)] = prevSide->getTiles()[0][col];
	kube->getBack()->getTiles()[reverseIndex(1)][reverseIndex(col)] = prevSide->getTiles()[1][col];
	kube->getBack()->getTiles()[reverseIndex(2)][reverseIndex(col)] = prevSide->getTiles()[2][col];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][col] = buffer[0];
	prevSide->getTiles()[1][col] = buffer[1];
	prevSide->getTiles()[2][col] = buffer[2];
}

void KubeNavigator::moveVerticalZ(bool clockwise, bool straight, int row, int col)
{
	KubeSide *nextSide;
	KubeSide *prevSide;

	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getUpper()->getTiles()[row][0];
	buffer[1] = kube->getUpper()->getTiles()[row][1];
	buffer[2] = kube->getUpper()->getTiles()[row][2];

	if (clockwise ^ straight)
	{
		nextSide = kube->getRight();
		prevSide = kube->getLeft();
	}
	else
	{
		nextSide = kube->getLeft();
		prevSide = kube->getRight();
	}

	/* Front Side */
	kube->getUpper()->getTiles()[row][0] = nextSide->getTiles()[0][col];
	kube->getUpper()->getTiles()[row][1] = nextSide->getTiles()[1][col];
	kube->getUpper()->getTiles()[row][2] = nextSide->getTiles()[2][col];

	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][col] = kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(0)];
	nextSide->getTiles()[1][col] = kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(1)];
	nextSide->getTiles()[2][col] = kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(2)];

	/* Back Side */
	kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(0)] = prevSide->getTiles()[0][col];
	kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(1)] = prevSide->getTiles()[1][col];
	kube->getBottom()->getTiles()[reverseIndex(row)][reverseIndex(2)] = prevSide->getTiles()[2][col];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][reverseIndex(col)] = buffer[0];
	prevSide->getTiles()[1][reverseIndex(col)] = buffer[1];
	prevSide->getTiles()[2][reverseIndex(col)] = buffer[2];
}

void KubeNavigator::moveFace(bool clockwise, bool straight, KubeSide *faceSide)
{
	KubeSide::Color *buffer = new KubeSide::Color[4];

	buffer[0] = faceSide->getTiles()[0][0];
	buffer[1] = faceSide->getTiles()[0][1];

	if (clockwise && straight)
	{
		buffer[2] = faceSide->getTiles()[0][2];
		buffer[3] = faceSide->getTiles()[1][2];

		/* First Row */
		faceSide->getTiles()[0][0] = faceSide->getTiles()[2][0];
		faceSide->getTiles()[0][1] = faceSide->getTiles()[1][0];
		faceSide->getTiles()[0][2] = buffer[0];

		/* Second Row */
		faceSide->getTiles()[1][0] = faceSide->getTiles()[2][1];
		faceSide->getTiles()[1][2] = buffer[1];
		
		/* Third Row */
		faceSide->getTiles()[2][0] = faceSide->getTiles()[2][2];
		faceSide->getTiles()[2][1] = buffer[3];
		faceSide->getTiles()[2][2] = buffer[2];
	}
	else
	{
		buffer[2] = faceSide->getTiles()[1][0];
		buffer[3] = faceSide->getTiles()[2][0];

		/* First Row */
		faceSide->getTiles()[0][0] = faceSide->getTiles()[0][2];
		faceSide->getTiles()[0][1] = faceSide->getTiles()[1][2];
		faceSide->getTiles()[0][2] = faceSide->getTiles()[2][2];

		/* Second Row */
		faceSide->getTiles()[1][0] = buffer[1];
		faceSide->getTiles()[1][2] = faceSide->getTiles()[2][1];
		
		/* Third Row */
		faceSide->getTiles()[2][0] = buffer[0];
		faceSide->getTiles()[2][1] = buffer[2];
		faceSide->getTiles()[2][2] = buffer[3];
	}
}

void KubeNavigator::moveDouble(KubeNavigator::moveMethod method)
{
	this->doubleMove = true;

	(this->*method)();
	(this->*method)();

	this->doubleMove = false;
}

void KubeNavigator::traceMove(KubeTracer::Move move)
{
	if (!this->doubleMove)
	{
		if (useTracer)
		{
			tracer->traceMove(move);
		}

		if (printMove)
		{
			printer->printKube();
		}
	}
}


void KubeNavigator::makeTheMove(KubeTracer::Move move)
{
	switch(move)
	{
		case KubeTracer::UP:
			up();
			return;

		case KubeTracer::ANTI_UP:
			aUp();
			return;

		case KubeTracer::DOUBLE_UP:
			up2();
			return;

		case KubeTracer::DOWN:
			down();
			return;

		case KubeTracer::ANTI_DOWN:
			aDown();
			return;

		case KubeTracer::DOUBLE_DOWN:
			down2();
			return;

		case KubeTracer::LEFT:
			left();
			return;

		case KubeTracer::ANTI_LEFT:
			aLeft();
			return;

		case KubeTracer::DOUBLE_LEFT:
			left2();
			return;

		case KubeTracer::RIGHT:
			right();
			return;

		case KubeTracer::ANTI_RIGHT:
			aRight();
			return;

		case KubeTracer::DOUBLE_RIGHT:
			right2();
			return;

		case KubeTracer::FRONT :
			front();
			return;

		case KubeTracer::ANTI_FRONT:
			aFront();
			return;

		case KubeTracer::DOUBLE_FRONT :
			front2();
			return;

		case KubeTracer::BACK :
			back();
			return;

		case KubeTracer::ANTI_BACK :
			aBack();
			return;

		case KubeTracer::DOUBLE_BACK :
			back2();
			return;

		case KubeTracer::X:
			moveX();
			return;

		case KubeTracer::ANTI_X :
			moveAx();
			return;

		case KubeTracer::DOUBLE_X :
			moveX2();
			return;

		case KubeTracer::Y :
			moveY();
			return;

		case KubeTracer::ANTI_Y :
			moveAy();
			return;

		case KubeTracer::DOUBLE_Y :
			moveY2();
			return;

		case KubeTracer::Z :
			moveZ();
			return;

		case KubeTracer::ANTI_Z :
			moveAz();
			return;

		case KubeTracer::DOUBLE_Z :
			moveZ2();
			return;
	}
}



void KubeNavigator::up()
{
	bool clockwise = true;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());


	traceMove(KubeTracer::UP);
}

void KubeNavigator::aUp()
{
	bool clockwise = false;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());


	traceMove(KubeTracer::ANTI_UP);
}

void KubeNavigator::up2()
{
	moveDouble(&KubeNavigator::up);

	traceMove(KubeTracer::DOUBLE_UP);
}



void KubeNavigator::down()
{
	bool clockwise = true;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, !straight, kube->getBottom());


	traceMove(KubeTracer::DOWN);
}

void KubeNavigator::aDown()
{
	bool clockwise = false;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, !straight, kube->getBottom());


	traceMove(KubeTracer::ANTI_DOWN);
}

void KubeNavigator::down2()
{
	moveDouble(&KubeNavigator::down);

	traceMove(KubeTracer::DOUBLE_DOWN);
}



void KubeNavigator::left()
{
	bool clockwise = true;
	bool straight = false;

	moveVerticalX(clockwise, straight, 0);

	moveFace(clockwise, !straight, kube->getLeft());


	traceMove(KubeTracer::LEFT);
}

void KubeNavigator::aLeft()
{
	bool clockwise = false;
	bool straight = false;

	moveVerticalX(clockwise, straight, 0);

	moveFace(clockwise, !straight, kube->getLeft());


	traceMove(KubeTracer::ANTI_LEFT);
}

void KubeNavigator::left2()
{
	moveDouble(&KubeNavigator::left);

	traceMove(KubeTracer::DOUBLE_LEFT);
}



void KubeNavigator::right()
{
	bool clockwise = true;
	bool straight = true;

	moveVerticalX(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());


	traceMove(KubeTracer::RIGHT);
}

void KubeNavigator::aRight()
{
	bool clockwise = false;
	bool straight = true;

	moveVerticalX(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());


	traceMove(KubeTracer::ANTI_RIGHT);
}

void KubeNavigator::right2()
{
	moveDouble(&KubeNavigator::right);

	traceMove(KubeTracer::DOUBLE_RIGHT);
}



void KubeNavigator::front()
{
	bool clockwise = true;
	bool straight = true;

	


	KubeSide *nextSide;
	KubeSide *prevSide;

	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getUpper()->getTiles()[2][0];
	buffer[1] = kube->getUpper()->getTiles()[2][1];
	buffer[2] = kube->getUpper()->getTiles()[2][2];

	nextSide = kube->getLeft();
	prevSide = kube->getRight();



	/* Upper Side */
	kube->getUpper()->getTiles()[2][0] = nextSide->getTiles()[2][2];
	kube->getUpper()->getTiles()[2][1] = nextSide->getTiles()[1][2];
	kube->getUpper()->getTiles()[2][2] = nextSide->getTiles()[0][2];

	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][2] = kube->getBottom()->getTiles()[0][0];
	nextSide->getTiles()[1][2] = kube->getBottom()->getTiles()[0][1];
	nextSide->getTiles()[2][2] = kube->getBottom()->getTiles()[0][2];

	/* Back Side */
	kube->getBottom()->getTiles()[0][0] = prevSide->getTiles()[2][0];
	kube->getBottom()->getTiles()[0][1] = prevSide->getTiles()[1][0];
	kube->getBottom()->getTiles()[0][2] = prevSide->getTiles()[0][0];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][0] = buffer[0];
	prevSide->getTiles()[1][0] = buffer[1];
	prevSide->getTiles()[2][0] = buffer[2];





	moveFace(clockwise, straight, kube->getFront());


	traceMove(KubeTracer::FRONT);
}

void KubeNavigator::aFront()
{
	bool clockwise = false;
	bool straight = true;

	





	KubeSide *nextSide;	
	KubeSide *prevSide;

	nextSide = kube->getRight();
	prevSide = kube->getLeft();


	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getUpper()->getTiles()[2][0];
	buffer[1] = kube->getUpper()->getTiles()[2][1];
	buffer[2] = kube->getUpper()->getTiles()[2][2];


	/* Front Side */
	kube->getUpper()->getTiles()[2][0] = nextSide->getTiles()[0][0];
	kube->getUpper()->getTiles()[2][1] = nextSide->getTiles()[1][0];
	kube->getUpper()->getTiles()[2][2] = nextSide->getTiles()[2][0];

	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][0] = kube->getBottom()->getTiles()[0][2];
	nextSide->getTiles()[1][0] = kube->getBottom()->getTiles()[0][1];
	nextSide->getTiles()[2][0] = kube->getBottom()->getTiles()[0][0];

	/* Back Side */
	kube->getBottom()->getTiles()[0][0] = prevSide->getTiles()[0][2];
	kube->getBottom()->getTiles()[0][1] = prevSide->getTiles()[1][2];
	kube->getBottom()->getTiles()[0][2] = prevSide->getTiles()[2][2];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][2] = buffer[2];
	prevSide->getTiles()[1][2] = buffer[1];
	prevSide->getTiles()[2][2] = buffer[0];





	moveFace(clockwise, straight, kube->getFront());


	traceMove(KubeTracer::ANTI_FRONT);
}

void KubeNavigator::front2()
{
	moveDouble(&KubeNavigator::front);

	traceMove(KubeTracer::DOUBLE_FRONT);
}



void KubeNavigator::back()
{
	bool clockwise = true;
	bool straight = false;

	

	KubeSide *nextSide;
	KubeSide *prevSide;

	nextSide = kube->getRight();
	prevSide = kube->getLeft();



	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getUpper()->getTiles()[0][0];
	buffer[1] = kube->getUpper()->getTiles()[0][1];
	buffer[2] = kube->getUpper()->getTiles()[0][2];


	/* Front Side */
	kube->getUpper()->getTiles()[0][0] = nextSide->getTiles()[0][2];
	kube->getUpper()->getTiles()[0][1] = nextSide->getTiles()[1][2];
	kube->getUpper()->getTiles()[0][2] = nextSide->getTiles()[2][2];


	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][2] = kube->getBottom()->getTiles()[2][2];
	nextSide->getTiles()[1][2] = kube->getBottom()->getTiles()[2][1];
	nextSide->getTiles()[2][2] = kube->getBottom()->getTiles()[2][0];


	/* Back Side */
	kube->getBottom()->getTiles()[2][0] = prevSide->getTiles()[0][0];
	kube->getBottom()->getTiles()[2][1] = prevSide->getTiles()[1][0];
	kube->getBottom()->getTiles()[2][2] = prevSide->getTiles()[2][0];


	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][0] = buffer[2];
	prevSide->getTiles()[1][0] = buffer[1];
	prevSide->getTiles()[2][0] = buffer[0];





	moveFace(clockwise, !straight, kube->getBack());


	traceMove(KubeTracer::BACK);
}

void KubeNavigator::aBack()
{
	bool clockwise = false;
	bool straight = false;

	


	KubeSide *nextSide;
	KubeSide *prevSide;

	nextSide = kube->getLeft();
	prevSide = kube->getRight();



	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getUpper()->getTiles()[0][0];
	buffer[1] = kube->getUpper()->getTiles()[0][1];
	buffer[2] = kube->getUpper()->getTiles()[0][2];


	/* Upper Side */
	kube->getUpper()->getTiles()[0][0] = nextSide->getTiles()[2][0];
	kube->getUpper()->getTiles()[0][1] = nextSide->getTiles()[1][0];
	kube->getUpper()->getTiles()[0][2] = nextSide->getTiles()[0][0];


	/* Next Side (Right if clockwise else Left) */
	nextSide->getTiles()[0][0] = kube->getBottom()->getTiles()[2][0];
	nextSide->getTiles()[1][0] = kube->getBottom()->getTiles()[2][1];
	nextSide->getTiles()[2][0] = kube->getBottom()->getTiles()[2][2];


	/* Back Side */
	kube->getBottom()->getTiles()[2][0] = prevSide->getTiles()[2][2];
	kube->getBottom()->getTiles()[2][1] = prevSide->getTiles()[1][2];
	kube->getBottom()->getTiles()[2][2] = prevSide->getTiles()[0][2];


	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][2] = buffer[0];
	prevSide->getTiles()[1][2] = buffer[1];
	prevSide->getTiles()[2][2] = buffer[2];




	moveFace(clockwise, straight, kube->getBack());


	traceMove(KubeTracer::ANTI_BACK);
}

void KubeNavigator::back2()
{
	moveDouble(&KubeNavigator::back);

	traceMove(KubeTracer::DOUBLE_BACK);
}



void KubeNavigator::moveX()
{
	bool clockwise = true;
	bool straight = true;



	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[9];

	buffer[0] = kube->getUpper()->getTiles()[0][0];
	buffer[1] = kube->getUpper()->getTiles()[0][1];
	buffer[2] = kube->getUpper()->getTiles()[0][2];
	buffer[3] = kube->getUpper()->getTiles()[1][0];
	buffer[4] = kube->getUpper()->getTiles()[1][1];
	buffer[5] = kube->getUpper()->getTiles()[1][2];
	buffer[6] = kube->getUpper()->getTiles()[2][0];
	buffer[7] = kube->getUpper()->getTiles()[2][1];
	buffer[8] = kube->getUpper()->getTiles()[2][2];



	/* Upper Side */
	kube->getUpper()->getTiles()[0][0] = kube->getFront()->getTiles()[0][0];
	kube->getUpper()->getTiles()[0][1] = kube->getFront()->getTiles()[0][1];
	kube->getUpper()->getTiles()[0][2] = kube->getFront()->getTiles()[0][2];
	kube->getUpper()->getTiles()[1][0] = kube->getFront()->getTiles()[1][0];
	kube->getUpper()->getTiles()[1][1] = kube->getFront()->getTiles()[1][1];
	kube->getUpper()->getTiles()[1][2] = kube->getFront()->getTiles()[1][2];
	kube->getUpper()->getTiles()[2][0] = kube->getFront()->getTiles()[2][0];
	kube->getUpper()->getTiles()[2][1] = kube->getFront()->getTiles()[2][1];
	kube->getUpper()->getTiles()[2][2] = kube->getFront()->getTiles()[2][2];

	/* Front Side */
	kube->getFront()->getTiles()[0][0] = kube->getBottom()->getTiles()[0][0];
	kube->getFront()->getTiles()[0][1] = kube->getBottom()->getTiles()[0][1];
	kube->getFront()->getTiles()[0][2] = kube->getBottom()->getTiles()[0][2];
	kube->getFront()->getTiles()[1][0] = kube->getBottom()->getTiles()[1][0];
	kube->getFront()->getTiles()[1][1] = kube->getBottom()->getTiles()[1][1];
	kube->getFront()->getTiles()[1][2] = kube->getBottom()->getTiles()[1][2];
	kube->getFront()->getTiles()[2][0] = kube->getBottom()->getTiles()[2][0];
	kube->getFront()->getTiles()[2][1] = kube->getBottom()->getTiles()[2][1];
	kube->getFront()->getTiles()[2][2] = kube->getBottom()->getTiles()[2][2];


	/* Bottom Side */
	kube->getBottom()->getTiles()[0][0] = kube->getBack()->getTiles()[2][2];
	kube->getBottom()->getTiles()[0][1] = kube->getBack()->getTiles()[2][1];
	kube->getBottom()->getTiles()[0][2] = kube->getBack()->getTiles()[2][0];
	kube->getBottom()->getTiles()[1][0] = kube->getBack()->getTiles()[1][2];
	kube->getBottom()->getTiles()[1][1] = kube->getBack()->getTiles()[1][1];
	kube->getBottom()->getTiles()[1][2] = kube->getBack()->getTiles()[1][0];
	kube->getBottom()->getTiles()[2][0] = kube->getBack()->getTiles()[0][2];
	kube->getBottom()->getTiles()[2][1] = kube->getBack()->getTiles()[0][1];
	kube->getBottom()->getTiles()[2][2] = kube->getBack()->getTiles()[0][0];


	/* Back Side */
	kube->getBack()->getTiles()[0][0] = buffer[8];
	kube->getBack()->getTiles()[0][1] = buffer[7];
	kube->getBack()->getTiles()[0][2] = buffer[6];
	kube->getBack()->getTiles()[1][0] = buffer[5];
	kube->getBack()->getTiles()[1][1] = buffer[4];
	kube->getBack()->getTiles()[1][2] = buffer[3];
	kube->getBack()->getTiles()[2][0] = buffer[2];
	kube->getBack()->getTiles()[2][1] = buffer[1];
	kube->getBack()->getTiles()[2][2] = buffer[0];



	moveFace(clockwise, straight, kube->getRight());
	moveFace(!clockwise, straight, kube->getLeft());


	traceMove(KubeTracer::X);
}

void KubeNavigator::moveAx()
{
	bool clockwise = false;
	bool straight = true;



	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[9];

	buffer[0] = kube->getUpper()->getTiles()[0][0];
	buffer[1] = kube->getUpper()->getTiles()[0][1];
	buffer[2] = kube->getUpper()->getTiles()[0][2];
	buffer[3] = kube->getUpper()->getTiles()[1][0];
	buffer[4] = kube->getUpper()->getTiles()[1][1];
	buffer[5] = kube->getUpper()->getTiles()[1][2];
	buffer[6] = kube->getUpper()->getTiles()[2][0];
	buffer[7] = kube->getUpper()->getTiles()[2][1];
	buffer[8] = kube->getUpper()->getTiles()[2][2];



	/* Upper Side */
	kube->getUpper()->getTiles()[0][0] = kube->getBack()->getTiles()[2][2];
	kube->getUpper()->getTiles()[0][1] = kube->getBack()->getTiles()[2][1];
	kube->getUpper()->getTiles()[0][2] = kube->getBack()->getTiles()[2][0];
	kube->getUpper()->getTiles()[1][0] = kube->getBack()->getTiles()[1][2];
	kube->getUpper()->getTiles()[1][1] = kube->getBack()->getTiles()[1][1];
	kube->getUpper()->getTiles()[1][2] = kube->getBack()->getTiles()[1][0];
	kube->getUpper()->getTiles()[2][0] = kube->getBack()->getTiles()[0][2];
	kube->getUpper()->getTiles()[2][1] = kube->getBack()->getTiles()[0][1];
	kube->getUpper()->getTiles()[2][2] = kube->getBack()->getTiles()[0][0];

	/* Front Side */
	kube->getBack()->getTiles()[0][0] = kube->getBottom()->getTiles()[2][2];
	kube->getBack()->getTiles()[0][1] = kube->getBottom()->getTiles()[2][1];
	kube->getBack()->getTiles()[0][2] = kube->getBottom()->getTiles()[2][0];
	kube->getBack()->getTiles()[1][0] = kube->getBottom()->getTiles()[1][2];
	kube->getBack()->getTiles()[1][1] = kube->getBottom()->getTiles()[1][1];
	kube->getBack()->getTiles()[1][2] = kube->getBottom()->getTiles()[1][0];
	kube->getBack()->getTiles()[2][0] = kube->getBottom()->getTiles()[0][2];
	kube->getBack()->getTiles()[2][1] = kube->getBottom()->getTiles()[0][1];
	kube->getBack()->getTiles()[2][2] = kube->getBottom()->getTiles()[0][0];


	/* Bottom Side */
	kube->getBottom()->getTiles()[0][0] = kube->getFront()->getTiles()[0][0];
	kube->getBottom()->getTiles()[0][1] = kube->getFront()->getTiles()[0][1];
	kube->getBottom()->getTiles()[0][2] = kube->getFront()->getTiles()[0][2];
	kube->getBottom()->getTiles()[1][0] = kube->getFront()->getTiles()[1][0];
	kube->getBottom()->getTiles()[1][1] = kube->getFront()->getTiles()[1][1];
	kube->getBottom()->getTiles()[1][2] = kube->getFront()->getTiles()[1][2];
	kube->getBottom()->getTiles()[2][0] = kube->getFront()->getTiles()[2][0];
	kube->getBottom()->getTiles()[2][1] = kube->getFront()->getTiles()[2][1];
	kube->getBottom()->getTiles()[2][2] = kube->getFront()->getTiles()[2][2];


	/* Back Side */
	kube->getFront()->getTiles()[0][0] = buffer[0];
	kube->getFront()->getTiles()[0][1] = buffer[1];
	kube->getFront()->getTiles()[0][2] = buffer[2];
	kube->getFront()->getTiles()[1][0] = buffer[3];
	kube->getFront()->getTiles()[1][1] = buffer[4];
	kube->getFront()->getTiles()[1][2] = buffer[5];
	kube->getFront()->getTiles()[2][0] = buffer[6];
	kube->getFront()->getTiles()[2][1] = buffer[7];
	kube->getFront()->getTiles()[2][2] = buffer[8];



	moveFace(clockwise, straight, kube->getRight());
	moveFace(!clockwise, straight, kube->getLeft());


	traceMove(KubeTracer::ANTI_X);
}

void KubeNavigator::moveX2()
{
	moveDouble(&KubeNavigator::moveX);

	traceMove(KubeTracer::DOUBLE_X);
}



void KubeNavigator::moveY()
{
	bool clockwise = true;
	bool straight = true;


	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[9];

	buffer[0] = kube->getLeft()->getTiles()[0][0];
	buffer[1] = kube->getLeft()->getTiles()[0][1];
	buffer[2] = kube->getLeft()->getTiles()[0][2];
	buffer[3] = kube->getLeft()->getTiles()[1][0];
	buffer[4] = kube->getLeft()->getTiles()[1][1];
	buffer[5] = kube->getLeft()->getTiles()[1][2];
	buffer[6] = kube->getLeft()->getTiles()[2][0];
	buffer[7] = kube->getLeft()->getTiles()[2][1];
	buffer[8] = kube->getLeft()->getTiles()[2][2];



	/* Upper Side */
	kube->getLeft()->getTiles()[0][0] = kube->getFront()->getTiles()[0][0];
	kube->getLeft()->getTiles()[0][1] = kube->getFront()->getTiles()[0][1];
	kube->getLeft()->getTiles()[0][2] = kube->getFront()->getTiles()[0][2];
	kube->getLeft()->getTiles()[1][0] = kube->getFront()->getTiles()[1][0];
	kube->getLeft()->getTiles()[1][1] = kube->getFront()->getTiles()[1][1];
	kube->getLeft()->getTiles()[1][2] = kube->getFront()->getTiles()[1][2];
	kube->getLeft()->getTiles()[2][0] = kube->getFront()->getTiles()[2][0];
	kube->getLeft()->getTiles()[2][1] = kube->getFront()->getTiles()[2][1];
	kube->getLeft()->getTiles()[2][2] = kube->getFront()->getTiles()[2][2];

	/* Front Side */
	kube->getFront()->getTiles()[0][0] = kube->getRight()->getTiles()[0][0];
	kube->getFront()->getTiles()[0][1] = kube->getRight()->getTiles()[0][1];
	kube->getFront()->getTiles()[0][2] = kube->getRight()->getTiles()[0][2];
	kube->getFront()->getTiles()[1][0] = kube->getRight()->getTiles()[1][0];
	kube->getFront()->getTiles()[1][1] = kube->getRight()->getTiles()[1][1];
	kube->getFront()->getTiles()[1][2] = kube->getRight()->getTiles()[1][2];
	kube->getFront()->getTiles()[2][0] = kube->getRight()->getTiles()[2][0];
	kube->getFront()->getTiles()[2][1] = kube->getRight()->getTiles()[2][1];
	kube->getFront()->getTiles()[2][2] = kube->getRight()->getTiles()[2][2];


	/* Bottom Side */
	kube->getRight()->getTiles()[0][0] = kube->getBack()->getTiles()[0][0];
	kube->getRight()->getTiles()[0][1] = kube->getBack()->getTiles()[0][1];
	kube->getRight()->getTiles()[0][2] = kube->getBack()->getTiles()[0][2];
	kube->getRight()->getTiles()[1][0] = kube->getBack()->getTiles()[1][0];
	kube->getRight()->getTiles()[1][1] = kube->getBack()->getTiles()[1][1];
	kube->getRight()->getTiles()[1][2] = kube->getBack()->getTiles()[1][2];
	kube->getRight()->getTiles()[2][0] = kube->getBack()->getTiles()[2][0];
	kube->getRight()->getTiles()[2][1] = kube->getBack()->getTiles()[2][1];
	kube->getRight()->getTiles()[2][2] = kube->getBack()->getTiles()[2][2];


	/* Back Side */
	kube->getBack()->getTiles()[0][0] = buffer[0];
	kube->getBack()->getTiles()[0][1] = buffer[1];
	kube->getBack()->getTiles()[0][2] = buffer[2];
	kube->getBack()->getTiles()[1][0] = buffer[3];
	kube->getBack()->getTiles()[1][1] = buffer[4];
	kube->getBack()->getTiles()[1][2] = buffer[5];
	kube->getBack()->getTiles()[2][0] = buffer[6];
	kube->getBack()->getTiles()[2][1] = buffer[7];
	kube->getBack()->getTiles()[2][2] = buffer[8];


	moveFace(clockwise, straight, kube->getUpper());
	moveFace(!clockwise, straight, kube->getBottom());


	traceMove(KubeTracer::Y);
}

void KubeNavigator::moveAy()
{
	bool clockwise = false;
	bool straight = true;


	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[9];

	buffer[0] = kube->getRight()->getTiles()[0][0];
	buffer[1] = kube->getRight()->getTiles()[0][1];
	buffer[2] = kube->getRight()->getTiles()[0][2];
	buffer[3] = kube->getRight()->getTiles()[1][0];
	buffer[4] = kube->getRight()->getTiles()[1][1];
	buffer[5] = kube->getRight()->getTiles()[1][2];
	buffer[6] = kube->getRight()->getTiles()[2][0];
	buffer[7] = kube->getRight()->getTiles()[2][1];
	buffer[8] = kube->getRight()->getTiles()[2][2];



	/* Upper Side */
	kube->getRight()->getTiles()[0][0] = kube->getFront()->getTiles()[0][0];
	kube->getRight()->getTiles()[0][1] = kube->getFront()->getTiles()[0][1];
	kube->getRight()->getTiles()[0][2] = kube->getFront()->getTiles()[0][2];
	kube->getRight()->getTiles()[1][0] = kube->getFront()->getTiles()[1][0];
	kube->getRight()->getTiles()[1][1] = kube->getFront()->getTiles()[1][1];
	kube->getRight()->getTiles()[1][2] = kube->getFront()->getTiles()[1][2];
	kube->getRight()->getTiles()[2][0] = kube->getFront()->getTiles()[2][0];
	kube->getRight()->getTiles()[2][1] = kube->getFront()->getTiles()[2][1];
	kube->getRight()->getTiles()[2][2] = kube->getFront()->getTiles()[2][2];

	/* Front Side */
	kube->getFront()->getTiles()[0][0] = kube->getLeft()->getTiles()[0][0];
	kube->getFront()->getTiles()[0][1] = kube->getLeft()->getTiles()[0][1];
	kube->getFront()->getTiles()[0][2] = kube->getLeft()->getTiles()[0][2];
	kube->getFront()->getTiles()[1][0] = kube->getLeft()->getTiles()[1][0];
	kube->getFront()->getTiles()[1][1] = kube->getLeft()->getTiles()[1][1];
	kube->getFront()->getTiles()[1][2] = kube->getLeft()->getTiles()[1][2];
	kube->getFront()->getTiles()[2][0] = kube->getLeft()->getTiles()[2][0];
	kube->getFront()->getTiles()[2][1] = kube->getLeft()->getTiles()[2][1];
	kube->getFront()->getTiles()[2][2] = kube->getLeft()->getTiles()[2][2];


	/* Bottom Side */
	kube->getLeft()->getTiles()[0][0] = kube->getBack()->getTiles()[0][0];
	kube->getLeft()->getTiles()[0][1] = kube->getBack()->getTiles()[0][1];
	kube->getLeft()->getTiles()[0][2] = kube->getBack()->getTiles()[0][2];
	kube->getLeft()->getTiles()[1][0] = kube->getBack()->getTiles()[1][0];
	kube->getLeft()->getTiles()[1][1] = kube->getBack()->getTiles()[1][1];
	kube->getLeft()->getTiles()[1][2] = kube->getBack()->getTiles()[1][2];
	kube->getLeft()->getTiles()[2][0] = kube->getBack()->getTiles()[2][0];
	kube->getLeft()->getTiles()[2][1] = kube->getBack()->getTiles()[2][1];
	kube->getLeft()->getTiles()[2][2] = kube->getBack()->getTiles()[2][2];


	/* Back Side */
	kube->getBack()->getTiles()[0][0] = buffer[0];
	kube->getBack()->getTiles()[0][1] = buffer[1];
	kube->getBack()->getTiles()[0][2] = buffer[2];
	kube->getBack()->getTiles()[1][0] = buffer[3];
	kube->getBack()->getTiles()[1][1] = buffer[4];
	kube->getBack()->getTiles()[1][2] = buffer[5];
	kube->getBack()->getTiles()[2][0] = buffer[6];
	kube->getBack()->getTiles()[2][1] = buffer[7];
	kube->getBack()->getTiles()[2][2] = buffer[8];


	moveFace(clockwise, straight, kube->getUpper());
	moveFace(!clockwise, straight, kube->getBottom());


	traceMove(KubeTracer::ANTI_Y);
}

void KubeNavigator::moveY2()
{
	moveDouble(&KubeNavigator::moveY);

	traceMove(KubeTracer::DOUBLE_Y);
}



void KubeNavigator::moveZ()
{
	traceMove(KubeTracer::Z);
}

void KubeNavigator::moveAz()
{
	traceMove(KubeTracer::ANTI_Z);
}

void KubeNavigator::moveZ2()
{
	moveDouble(&KubeNavigator::moveZ);

	traceMove(KubeTracer::DOUBLE_Z);
}