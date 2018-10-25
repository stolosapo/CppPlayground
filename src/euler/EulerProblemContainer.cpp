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
		this->addMenuItem(new Problem001(logSrv));
		this->addMenuItem(new Problem002(logSrv));
		this->addMenuItem(new Problem003(logSrv));
		this->addMenuItem(new Problem004(logSrv));
		this->addMenuItem(new Problem005(logSrv));
		this->addMenuItem(new Problem006(logSrv));
		this->addMenuItem(new Problem007(logSrv));
		this->addMenuItem(new Problem008(logSrv));
		this->addMenuItem(new Problem009(logSrv));
		this->addMenuItem(new Problem010(logSrv));
	}

	virtual string getHeader()
	{
		EulerProblemHeader header;
		return header.getRandomHeader();
	}

};
