#ifndef IcecastMenuContainer_h__
#define IcecastMenuContainer_h__

#include <iostream>
#include <string>
#include "../../shared/Container.h"

using namespace std;

class IcecastMenuContainer : public Container
{
public:
	IcecastMenuContainer();

	virtual ~IcecastMenuContainer();

protected:
	virtual void fillOptions();

	virtual string getHeader();

};

#endif // IcecastMenuContainer_h__