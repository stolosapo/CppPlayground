#ifndef Sudoku_h__
#define Sudoku_h__

#include <iostream>
#include "Cell.h"

class Sudoku 
{
private:
	int dimension;
	int size;

	bool solved;

	Cell** cells;


	/* METHODS */
	void refreshCells();

	void applySolvedCheck();

	void applyHorizondialRule(int row);
	void applyVerticalRule(int column);
	void applySquareRule(int block);

public:
	Sudoku(int dimension);
	virtual ~Sudoku();

	/* GETTERS */
	int getDimension();
	int getSize();

	bool isSolved();

	Cell** getCells();


	/* METHODS */
	void initialize();
	void solve();

};

#endif // Sudoku_h__