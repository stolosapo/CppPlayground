#include <iostream>
#include <string>
#include "../kernel/menu/MenuContainer.h"
#include "Problem001.cpp"
#include "Problem002.cpp"
#include "Problem003.cpp"
#include "Problem004.cpp"
#include "Problem005.cpp"
#include "Problem006.cpp"
#include "Problem007.cpp"
#include "Problem008.cpp"
#include "Problem009.cpp"
#include "Problem010.cpp"
#include "EulerProblemHeader.cpp"

using namespace std;

class EulerProblemContainer : public MenuContainer
{
public:
	EulerProblemContainer() : MenuContainer(
		2,
		"Euler Problems",
		"Euler Problems")
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
		this->addMenuItem(8, new Problem009(logSrv));
		this->addMenuItem(9, new Problem010(logSrv));
	}

	virtual string getHeader()
	{
		EulerProblemHeader header;
		return header.getRandomHeader();
	}

};
