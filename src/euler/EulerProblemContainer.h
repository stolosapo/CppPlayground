#ifndef EulerProblemContainer_h__
#define EulerProblemContainer_h__

#include <iostream>
#include <string>
#include "../shared/Container.h"

using namespace std;

class EulerProblemContainer : public Container
{
public:
	EulerProblemContainer();
	virtual ~EulerProblemContainer();

protected:
	virtual void execute(int menuItemId);
	virtual void fillOptions();

};

#endif // EulerProblemContainer_h__