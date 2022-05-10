#ifndef CELLFACTORY_h__
#define CELLFACTORY_h__

#include <iostream>
#include "Cell.h"

class CellFactory
{
public:
	CellFactory();
	virtual ~CellFactory();
	
	static Cell* create(
		const int size, 
		int row, 
		int column, 
		int blockRow,
		int blockColumn,
		int value);
};

#endif // #ifndef CELLFACTORY_h__