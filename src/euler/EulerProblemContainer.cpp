#include <iostream>
#include <string>
#include "../shared/Container.h"
#include "Problem001.cpp"
#include "Problem002.cpp"
#include "Problem003.cpp"
#include "Problem004.cpp"

using namespace std;

class EulerProblemContainer : public Container
{
public:
	EulerProblemContainer() : Container(
		1, 
		"Euler Problems",
		"Euler Problems",
		4)
	{
		this->setContinueQuestion(true);
	}

	virtual ~EulerProblemContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new Problem001(logSrv));
		this->addMenuItem(1, new Problem002(logSrv));
		this->addMenuItem(2, new Problem003(logSrv));
		this->addMenuItem(3, new Problem004(logSrv));
	}

};