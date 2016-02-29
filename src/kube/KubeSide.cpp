#include "KubeSide.h"

KubeSide::KubeSide()
{
	tiles = new KubeSide::Color*[3];
	for (int i = 0; i < 3; ++i)
	{
		tiles[i] = new KubeSide::Color[3];
	}
}

KubeSide::~KubeSide()
{
	for (int i = 0; i < 3; ++i)
	{
		delete[] tiles[i];
	}

	delete[] tiles;
}

KubeSide::Color** KubeSide::getTiles()
{
	return tiles;
}

void KubeSide::setMainColor(Color mainColor)
{
	this->mainColor = mainColor;
}

void KubeSide::setTile(int row, int col, KubeSide::Color color)
{
	tiles[row][col] = color;
}