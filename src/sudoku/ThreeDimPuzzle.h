#ifndef ThreeDimPuzzle_h__
#define ThreeDimPuzzle_h__

#include <iostream>
#include <string>
#include "../menu/MenuItem.h"
#include "../log/ILogService.h"

using namespace std;

class ThreeDimPuzzle : public MenuItem
{
public:
	ThreeDimPuzzle();
	virtual ~ThreeDimPuzzle();

	virtual void action();
};
#endif // ThreeDimPuzzle_h__