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
	void applyHorizondialRule(int row);
	void applyVerticalRule(int column);
	void applySquareRule(int block);

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

};

#endif // SUDOKU_h__