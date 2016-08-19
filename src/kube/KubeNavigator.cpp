#include <iostream>
#include "KubeNavigator.h"

using namespace std;

KubeNavigator::KubeNavigator(Kube *kube)
{
	this->kube = kube;
}

KubeNavigator::~KubeNavigator()
{

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




void KubeNavigator::up()
{
	bool clockwise = true;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());
}

void KubeNavigator::aUp()
{
	bool clockwise = false;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());
}

void KubeNavigator::up2()
{
	up();
	up();
}



void KubeNavigator::down()
{
	bool clockwise = true;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, !straight, kube->getBottom());
}

void KubeNavigator::aDown()
{
	bool clockwise = false;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, !straight, kube->getBottom());
}

void KubeNavigator::down2()
{
	down();
	down();
}



void KubeNavigator::left()
{
	bool clockwise = true;
	bool straight = false;

	moveVerticalX(clockwise, straight, 0);

	moveFace(clockwise, !straight, kube->getLeft());
}

void KubeNavigator::aLeft()
{
	bool clockwise = false;
	bool straight = false;

	moveVerticalX(clockwise, straight, 0);

	moveFace(clockwise, !straight, kube->getLeft());
}

void KubeNavigator::left2()
{
	left();
	left();
}



void KubeNavigator::right()
{
	bool clockwise = true;
	bool straight = true;

	moveVerticalX(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());
}

void KubeNavigator::aRight()
{
	bool clockwise = false;
	bool straight = true;

	moveVerticalX(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());
}

void KubeNavigator::right2()
{
	right();
	right();
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
}

void KubeNavigator::front2()
{
	front();
	front();
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
}

void KubeNavigator::back2()
{
	back();
	back();
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
}

void KubeNavigator::moveX2()
{
	moveX();
	moveX();
}



void KubeNavigator::moveY()
{
	bool clockwise = true;
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
}

void KubeNavigator::moveAy()
{
	bool clockwise = false;
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
}

void KubeNavigator::moveY2()
{
	moveY();
	moveY();
}



void KubeNavigator::moveZ()
{

}

void KubeNavigator::moveAz()
{

}

void KubeNavigator::moveZ2()
{
	moveZ();
	moveZ();
}