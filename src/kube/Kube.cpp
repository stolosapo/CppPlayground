#include "Kube.h"
#include <cstddef>

Kube::Kube()
{
	this->front = NULL;
	this->right = NULL;
	this->back = NULL;
	this->left = NULL;
	this->upper = NULL;
	this->bottom = NULL;
}

Kube::~Kube()
{

}

KubeSide* Kube::getFront()
{
	return this->front;
}

KubeSide* Kube::getRight()
{
	return this->right;
}

KubeSide* Kube::getBack()
{
	return this->back;
}

KubeSide* Kube::getLeft()
{
	return this->left;
}

KubeSide* Kube::getUpper()
{
	return this->upper;
}

KubeSide* Kube::getBottom()
{
	return this->bottom;
}


void Kube::setFront(KubeSide *side)
{
	this->front = side;
}

void Kube::setRight(KubeSide *side)
{
	this->right = side;
}

void Kube::setBack(KubeSide *side)
{
	this->back = side;
}

void Kube::setLeft(KubeSide *side)
{
	this->left = side;
}

void Kube::setUpper(KubeSide *side)
{
	this->upper = side;
}

void Kube::setBottom(KubeSide *side)
{
	this->bottom = side;
}
