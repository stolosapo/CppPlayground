#include <iostream>
#include "Cell.h"
#include "Sudoku.h"

Sudoku::Sudoku(const int dimension)
{
	const int c_size = dimension * dimension;

	this->dimension = dimension;
	this->size = size;

	this->cells = new Cell *[c_size];
}

Sudoku::~Sudoku()
{
	for(int i = 0; i < this->size; ++i)
	{
	  delete[] this->cells[i];
	}

	delete[] this->cells;
}


/* GETTERS */
int Sudoku::getDimension()
{
	return this->dimension;
}

int Sudoku::getSize()
{
	return this->size;
}

bool Sudoku::isSolved()
{
	return this->solved;
}

Cell** Sudoku::getCells()
{
	return this->cells;
}



/* PRIVATE METHODS */
void Sudoku::refreshCells()
{

}

void Sudoku::applySolvedCheck()
{

}

void Sudoku::applyHorizondialRule(int row)
{

}

void Sudoku::applyVerticalRule(int column)
{

}

void Sudoku::applySquareRule(int block)
{

}



/* PUBLIC METHODS */
void Sudoku::initialize()
{

}

void Sudoku::solve()
{

}