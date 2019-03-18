#include <iostream>
#include <string>
#include "../kernel/menu/MenuItem.h"
#include "ThreeDimPuzzle.h"
#include "Sudoku.h"

using namespace std;

ThreeDimPuzzle::ThreeDimPuzzle() : MenuItem()
{
	this->setId(1);
	this->setName("Three On Three Puzzle");
	this->setTitle("3x3 Puzzle");
	this->setDescription("3x3 Puzzle");
}

ThreeDimPuzzle::~ThreeDimPuzzle()
{

}

void ThreeDimPuzzle::action()
{
	Sudoku *sudoku = new Sudoku(3);

	sudoku->initialize();
	sudoku->solve();

}
