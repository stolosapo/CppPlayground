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
	Cell* cell = new Cell(size);

	cell->setRow(row);
	cell->setColumn(row);

	cell->setBlockRow(blockRow);
	cell->setBlockColumn(blockColumn);

	cell->setValue(value);

	cell->setFound(false);

	return cell;
}