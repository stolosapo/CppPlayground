#include "Kube.h"
#include <cstddef>

Kube::Kube()
{
	this->mapper = new KubeColorMapper *[6];

	this->front = NULL;
	this->right = NULL;
	this->back = NULL;
	this->left = NULL;
	this->upper = NULL;
	this->bottom = NULL;
}

Kube::~Kube()
{
	if (mapper != NULL)
	{		
		for (int i = 0; i < 6; ++i)
		{
			delete[] mapper[i];
		}

		delete[] mapper;
	}

	if (this->front != NULL)
	{
		this->front = NULL;
	}

	if (this->right != NULL)
	{
		this->right = NULL;
	}

	if (this->back != NULL)
	{
		this->back = NULL;
	}

	if (this->left != NULL)
	{
		this->left = NULL;
	}

	if (this->upper != NULL)
	{
		this->upper = NULL;
	}

	if (this->bottom != NULL)
	{
		this->bottom = NULL;
	}
}

KubeColorMapper** Kube::getColorMapper()
{
	return this->mapper;
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


KubeSide::Color Kube::getColor(char colorChar)
{
	for (int i = 0; i < 6; ++i)
	{
		KubeColorMapper *map = this->mapper[i];

		if (map->getColorChar() == colorChar)
		{
			return map->getSideColor();
		}
	}
}