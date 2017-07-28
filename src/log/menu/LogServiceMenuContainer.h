#ifndef LogServiceMenuContainer_h__
#define LogServiceMenuContainer_h__

#include <iostream>
#include <string>
#include "../../menu/MenuContainer.h"

using namespace std;

class LogServiceMenuContainer : public MenuContainer
{
public:
	LogServiceMenuContainer();
	virtual ~LogServiceMenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // LogServiceMenuContainer_h__
