#ifndef Cell_h__
#define Cell_h__

#include <iostream>

class Cell 
{
private:
	int size;

	int row;
	int column;
	int block;

	int value;

	int* possible;
	bool found;

public:
	Cell(const int size);
	virtual ~Cell();

	/* GETTERS */
	int getSize();

	int getRow();
	int getColumn();
	int getBlock();

	int getValue();

	int* getPossible();
	bool isFound();

	
	/* SETTERS */
	void setRow(int row);
	void setColumn(int column);
	void setBlock(int block);

	void setValue(int value);

	void setPossible(int* possible);
	void setFound(bool found);


	/* METHODS */
	void applyFoundCheck();
};

#endif // Cell_h__