#include <iostream>
#include <string>
#include "LogActionItem.h"
#include "../shared/Container.h"

using namespace std;

class LogServiceContainer : public Container
{
public:
	LogServiceContainer() : Container(
		1, 
		"Log Service Test",
		"Log Service Test",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~LogServiceContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new LogActionItem(logSrv));
	}

	virtual string getHeader()
	{
		return "";
	}

};