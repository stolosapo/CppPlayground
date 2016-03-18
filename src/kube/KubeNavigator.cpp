#include "KubeNavigator.h"

KubeNavigator::KubeNavigator(Kube *kube)
{
	this->kube = kube;
}

KubeNavigator::~KubeNavigator()
{

}


void KubeNavigator::front()
{
	KubeSide::Color *buffer = new KubeSide::Color[3];

	buffer[0] = kube->getFront()->getTiles()[0][0];
	buffer[1] = kube->getFront()->getTiles()[0][1];
	buffer[2] = kube->getFront()->getTiles()[0][2];

	kube->getFront()->getTiles()[0][0] = kube->getRight()->getTiles()[0][0];
	kube->getFront()->getTiles()[0][1] = kube->getRight()->getTiles()[0][1];
	kube->getFront()->getTiles()[0][2] = kube->getRight()->getTiles()[0][2];

	kube->getRight()->getTiles()[0][0] = kube->getBack()->getTiles()[0][0];
	kube->getRight()->getTiles()[0][1] = kube->getBack()->getTiles()[0][1];
	kube->getRight()->getTiles()[0][2] = kube->getBack()->getTiles()[0][2];

	kube->getBack()->getTiles()[0][0] = kube->getLeft()->getTiles()[0][0];
	kube->getBack()->getTiles()[0][1] = kube->getLeft()->getTiles()[0][1];
	kube->getBack()->getTiles()[0][2] = kube->getLeft()->getTiles()[0][2];

	kube->getBack()->getTiles()[0][0] = buffer[0];
	kube->getBack()->getTiles()[0][1] = buffer[1];
	kube->getBack()->getTiles()[0][2] = buffer[2];


	KubeSide *upper = kube->getUpper();

	KubeSide::Color *upperBuffer = new KubeSide::Color[3];

	upperBuffer[0] = upper->getTiles()[0][0];

	upper->getTiles()[0][0] = upper->getTiles()[2][0];
	upper->getTiles()[0][1] = upper->getTiles()[1][0];
	upper->getTiles()[0][2] = upperBuffer[0];

	upper->getTiles()[1][0] = upper->getTiles()[2][1];
	upper->getTiles()[2][0] = upper->getTiles()[2][2];
	
	upper->getTiles()[1][0] = upperBuffer[0];

	upper->getTiles()[2][2] = upperBuffer[0];

	upper->getTiles()[2][1] = upper->getTiles()[1][0];
}

void KubeNavigator::back()
{

}

void KubeNavigator::up()
{

}

void KubeNavigator::left()
{

}

void KubeNavigator::right()
{

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

}

void KubeNavigator::aLeft()
{

}

void KubeNavigator::aRight()
{

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
