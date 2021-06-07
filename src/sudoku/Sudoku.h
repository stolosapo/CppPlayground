#ifndef SUDOKU_h__
#define SUDOKU_h__

#include <iostream>
#include <string>
#include "Cell.h"

using namespace std;

class Sudoku 
{
private:
	int dimension;
	int size;
	int columnSize;

	bool solved;

	Cell** cells;


	/* METHODS */
	void applySolvedCheck();
	bool applyHorizondialRule(Cell *cell, int value);
	bool applyVerticalRule(Cell *cell, int value);
	bool applySquareRule(Cell *cell, int value);

	int findColumnBlock(int column);
	int findRowBlock(int row);

	void readSudokuFromFile();
	void refreshCells();

public:
	Sudoku(const int dimension);
	virtual ~Sudoku();

	/* GETTERS */
	int getDimension();
	int getSize();
	int getColumnSize();

	bool isSolved();

	Cell** getCells();


	/* METHODS */
	void initialize();
	void solve();
	void print();

};

#endif // SUDOKU_h__