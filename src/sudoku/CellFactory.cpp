#include <iostream>
#include "Cell.h"
#include "CellFactory.h"

CellFactory::CellFactory()
{

}

CellFactory::~CellFactory()
{

}

Cell* CellFactory::create(
		const int size, 
		int row, 
		int column, 
		int blockRow,
		int blockColumn,
		int value)
{

	bool found = false;
	Cell* cell = new Cell(size);

	cell->setRow(row);
	cell->setColumn(column);

	cell->setBlockRow(blockRow);
	cell->setBlockColumn(blockColumn);

	cell->setValue(value);

	if (value != 0)
	{
		found = true;
	}
	
	cell->setFound(found);

	return cell;
}