#include <iostream>
#include <string>
#include "../shared/Container.h"
#include "Problem001.cpp"
#include "Problem002.cpp"
#include "Problem003.cpp"
#include "Problem004.cpp"
#include "Problem005.cpp"
#include "Problem006.cpp"
#include "Problem007.cpp"
#include "Problem008.cpp"

using namespace std;

class EulerProblemContainer : public Container
{
public:
	EulerProblemContainer() : Container(
		1, 
		"Euler Problems",
		"Euler Problems",
		8)
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
		this->addMenuItem(4, new Problem005(logSrv));
		this->addMenuItem(5, new Problem006(logSrv));
		this->addMenuItem(6, new Problem007(logSrv));
		this->addMenuItem(7, new Problem008(logSrv));
	}

};