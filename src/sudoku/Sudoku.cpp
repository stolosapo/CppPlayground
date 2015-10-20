#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cell.h"
#include "Sudoku.h"
#include "CellFactory.h"
#include "../shared/FileReader.h"
#include "../shared/convert.h"

using namespace std;

Sudoku::Sudoku(const int dimension)
{
	const int c_size = dimension * dimension;

	this->dimension = dimension;
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

void Sudoku::readSudokuFromFile()
{
	string filePath = "sudoku.txt";

	FileReader* reader = new FileReader(filePath.c_str());

	reader->read();

	vector<string> lines = reader->getLines();

	if (lines.size() != this->dimension)
	{
		// TODO: throw Exception;
	}

	for (int row = 0; row < lines.size(); ++row)
	{
		string line = lines[row];

		if (line.length() != this->dimension)
		{
			// TODO: throw Exception;
		}

		for (int col = 0; col < this->dimension; ++col)
		{
			string chNum = line.substr(col, 1);

			int value = Convert<int>::StringToNumber(chNum);

			Cell* cell = CellFactory::create(
				this->dimension,
				row,
				col,
				0,
				0,
				value);

			int index = row * col;
			this->cells[index] = cell;

			cout << endl << index << " -> " << cell->getValue();
		}
	}
}

void Sudoku::refreshCells()
{
	
}



/* PUBLIC METHODS */
void Sudoku::initialize()
{
	readSudokuFromFile();
}

void Sudoku::solve()
{

}