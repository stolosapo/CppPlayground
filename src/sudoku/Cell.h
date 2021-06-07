#ifndef Cell_h__
#define Cell_h__

#include <iostream>

class Cell 
{
private:
	int size;

	int row;
	int column;
	int blockRow;
	int blockColumn;

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
	int getBlockRow();
	int getBlockColumn();

	int getValue();

	int* getPossible();
	bool isFound();

	
	/* SETTERS */
	void setRow(int row);
	void setColumn(int column);
	void setBlockRow(int blockRow);
	void setBlockColumn(int blockColumn);

	void setValue(int value);

	void setPossible(int* possible);
	void setFound(bool found);


	/* METHODS */
	void addPossible(int value);
	void applyFoundCheck();
};

#endif // Cell_h__