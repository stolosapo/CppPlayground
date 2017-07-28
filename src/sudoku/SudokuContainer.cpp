#include <iostream>
#include "../menu/MenuContainer.h"
#include "Sudoku.h"
#include "ThreeDimPuzzle.h"
#include "SudokuHeader.cpp"

class SudokuContainer : public MenuContainer
{
public:
	SudokuContainer() : MenuContainer(
		6,
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

	virtual string getHeader()
	{
		SudokuHeader header;
		return header.getRandomHeader();
	}

};
