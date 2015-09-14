#include <iostream>
#include "../shared/Container.h"
#include "Sudoku.h"
#include "ThreeDimPuzzle.h"

class SudokuContainer : public Container
{
public:
	SudokuContainer() : Container(
		2, 
		"Sudoku Problems",
		"Sudoku Problems",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~SudokuContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new ThreeDimPuzzle);
	}

};