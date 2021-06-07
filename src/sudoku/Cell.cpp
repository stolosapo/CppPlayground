#include <iostream>
#include "Cell.h"

Cell::Cell(const int size)
{
	this->size = size;

	this->possible = new int[size];
}

Cell::~Cell()
{
	delete[] this->possible;
}


/* GETTERS */
int Cell::getRow()
{
	return this->row;
}

int Cell::getColumn()
{
	return this->column;
}

int Cell::getBlockRow()
{
	return this->blockRow;
}

int Cell::getBlockColumn()
{
	return this->blockColumn;
}

int Cell::getValue()
{
	return this->value;
}

int* Cell::getPossible()
{
	return this->possible;
}

bool Cell::isFound()
{
	return this->found;
}


/* SETTERS */
void Cell::setRow(int row)
{
	this->row = row;
}

void Cell::setColumn(int column)
{
	this->column = column;
}

void Cell::setBlockRow(int blockRow)
{
	this->blockRow = blockRow;
}

void Cell::setBlockColumn(int blockColumn)
{
	this->blockColumn = blockColumn;
}

void Cell::setValue(int value)
{
	this->value = value;

	if (value != 0)
	{
		this->found = true;

		for (int i = 0; i < this->size; ++i)
		{
			this->possible[i] = 0;
		}
	}
}

void Cell::setPossible(int* possible)
{
	this->possible = possible;
}

void Cell::setFound(bool found)
{
	this->found = found;
}


/* METHODS */
void Cell::addPossible(int value)
{
	this->possible[value] = value;
}

void Cell::applyFoundCheck()
{
	int cnt = 0;
	int index = -1;

	for (int i = 0; i < this->size; ++i)
	{
		if (this->possible[i] != 0)
		{
			cnt++;
			index = i;
		}
	}

	if (cnt == 1)
	{
		this->setValue(this->possible[index]);
	}
}