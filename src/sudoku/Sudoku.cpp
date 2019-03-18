#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cell.h"
#include "Sudoku.h"
#include "CellFactory.h"
#include "../kernel/utils/FileReader.h"
#include "../kernel/converter/Convert.h"

using namespace std;

Sudoku::Sudoku(const int dimension)
{
	const int col_size = dimension * dimension;
	const int c_size = col_size * col_size;

	this->dimension = dimension;
	this->columnSize = col_size;
	this->size = c_size;

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

void Sudoku::applySolvedCheck()
{
	bool found = true;

	for (int i = 0; i < this->size; ++i)
	{
		Cell *currentCell = this->cells[i];

		found &= currentCell->isFound();
	}

	this->solved = found;
}

bool Sudoku::applyHorizondialRule(Cell *cell, int value)
{
	int currentColumn = cell->getColumn();
	int currentRow = cell->getRow();

	for (int i = 0; i < this->size; ++i)
	{
		Cell *currentCell = this->cells[i];

		if (currentCell->getColumn() == currentColumn &&
			currentCell->getRow() != currentRow &&
			currentCell->isFound() &&
			currentCell->getValue() == value)
		{

			return false;

		}
	}

	return true;
}

bool Sudoku::applyVerticalRule(Cell *cell, int value)
{
	int currentColumn = cell->getColumn();
	int currentRow = cell->getRow();

	for (int i = 0; i < this->size; ++i)
	{
		Cell *currentCell = this->cells[i];

		if (currentCell->getColumn() != currentColumn &&
			currentCell->getRow() == currentRow &&
			currentCell->isFound() &&
			currentCell->getValue() == value)
		{

			return false;

		}
	}

	return true;
}

bool Sudoku::applySquareRule(Cell *cell, int value)
{
	return true;
}


int Sudoku::findColumnBlock(int column)
{
	return column / this->dimension;
}

int Sudoku::findRowBlock(int row)
{
	return row / this->dimension;
}


void Sudoku::readSudokuFromFile()
{
	string filePath = "sudoku.txt";
	int index = 0;

	FileReader* reader = new FileReader(filePath.c_str());

	reader->read();

	vector<string> lines = reader->getLines();

	if (lines.size() != this->columnSize)
	{
		// TODO: throw Exception;
	}


	for (int row = 0; row < lines.size(); ++row)
	{
		string line = lines[row];

		if (line.length() != this->columnSize)
		{
			// TODO: throw Exception;
		}

		for (int col = 0; col < this->columnSize; ++col)
		{
			string chNum = line.substr(col, 1);

			int value = Convert<int>::StringToNumber(chNum);

			Cell* cell = CellFactory::create(
				this->columnSize,
				row,
				col,
				findRowBlock(row),
				findColumnBlock(col),
				value);

			this->cells[index] = cell;

			index++;
		}
	}
}

void Sudoku::refreshCells()
{
	for (int i = 0; i < this->size; ++i)
	{
		Cell* cell = this->cells[i];

		if (!cell->isFound())
		{

			for (int posValue = 1; posValue <= this->columnSize; ++posValue)
			{
				bool isPossible = true;

				isPossible &= applyHorizondialRule(cell, posValue);

				isPossible &= applyVerticalRule(cell, posValue);

				// isPossible &= applySquareRule(cell, posValue);


				if (isPossible)
				{
					cell->addPossible(posValue);
				}

			}

			cell->applyFoundCheck();

			if (cell->isFound())
			{
				this->refreshCells();
				break;
			}
		}
	}
}



/* PUBLIC METHODS */
void Sudoku::initialize()
{
	readSudokuFromFile();

	refreshCells();
}

void Sudoku::solve()
{
	this->print();
}

void Sudoku::print()
{
	for (int i = 0; i < this->size; ++i)
	{
		Cell *cell = this->cells[i];

		cout << "(" << cell->getRow() << ", "
			 << cell->getColumn() << ") -> "
			 << cell->getValue() << endl;
	}
}
