#include <iostream>
#include <string>
#include "LogMenuItem.h"
#include "../../menu/MenuContainer.h"

using namespace std;

class LogServiceMenuContainer : public MenuContainer
{
public:
	LogServiceMenuContainer() : MenuContainer(
		1,
		"Log Service Test",
		"Log Service Test",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~LogServiceMenuContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new LogMenuItem(logSrv));
	}

	virtual string getHeader()
	{
		return "";
	}

};
