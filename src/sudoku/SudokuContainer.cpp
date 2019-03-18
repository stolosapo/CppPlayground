#include <iostream>
#include "../kernel/menu/MenuContainer.h"
#include "Sudoku.h"
#include "ThreeDimPuzzle.h"
#include "SudokuHeader.cpp"

class SudokuContainer : public MenuContainer
{
public:
	SudokuContainer() : MenuContainer(
		8,
		"Sudoku Problems",
		"Sudoku Problems")
	{
		this->setContinueQuestion(true);
	}

	virtual ~SudokuContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(new ThreeDimPuzzle);
	}

	virtual string getHeader()
	{
		SudokuHeader header;
		return header.getRandomHeader();
	}

};
