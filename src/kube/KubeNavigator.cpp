#include "KubeNavigator.h"

KubeNavigator::KubeNavigator(Kube *kube)
{
	this->kube = kube;
}

KubeNavigator::~KubeNavigator()
{

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

void KubeNavigator::moveVertical(bool clockwise, bool straight, int col)
{
	KubeSide *nextSide;
	KubeSide *prevSide;

	/* First Side column Buffer */
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getFront()->getTiles()[0][col];
	buffer[1] = kube->getFront()->getTiles()[1][col];
	buffer[2] = kube->getFront()->getTiles()[2][col];

	if (clockwise && straight)
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
	nextSide->getTiles()[0][col] = kube->getBack()->getTiles()[0][col];
	nextSide->getTiles()[1][col] = kube->getBack()->getTiles()[1][col];
	nextSide->getTiles()[2][col] = kube->getBack()->getTiles()[2][col];

	/* Back Side */
	kube->getBack()->getTiles()[0][col] = prevSide->getTiles()[0][col];
	kube->getBack()->getTiles()[1][col] = prevSide->getTiles()[1][col];
	kube->getBack()->getTiles()[2][col] = prevSide->getTiles()[2][col];

	/* Previous Side (Left if clockwise else Right) */
	prevSide->getTiles()[0][col] = buffer[0];
	prevSide->getTiles()[1][col] = buffer[1];
	prevSide->getTiles()[2][col] = buffer[2];
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

void KubeNavigator::front()
{

}

void KubeNavigator::back()
{

}

void KubeNavigator::up()
{
	bool clockwise = true;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());
}

void KubeNavigator::down()
{
	bool clockwise = true;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getBottom());
}

void KubeNavigator::left()
{
	bool clockwise = true;
	bool straight = true;

	moveVertical(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getLeft());
}

void KubeNavigator::right()
{
	bool clockwise = true;
	bool straight = false;

	moveVertical(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());
}


void KubeNavigator::moveX()
{

}

void KubeNavigator::moveY()
{

}

void KubeNavigator::moveZ()
{

}


void KubeNavigator::aFront()
{

}

void KubeNavigator::aBack()
{

}

void KubeNavigator::aUp()
{
	bool clockwise = false;
	bool straight = true;

	moveHorizontial(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getUpper());
}

void KubeNavigator::aDown()
{
	bool clockwise = false;
	bool straight = false;

	moveHorizontial(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getBottom());
}

void KubeNavigator::aLeft()
{
	bool clockwise = false;
	bool straight = true;

	moveVertical(clockwise, straight, 0);

	moveFace(clockwise, straight, kube->getLeft());
}

void KubeNavigator::aRight()
{
	bool clockwise = false;
	bool straight = false;

	moveVertical(clockwise, straight, 2);

	moveFace(clockwise, straight, kube->getRight());
}


void KubeNavigator::moveAx()
{

}

void KubeNavigator::moveAy()
{

}

void KubeNavigator::moveAz()
{

}
