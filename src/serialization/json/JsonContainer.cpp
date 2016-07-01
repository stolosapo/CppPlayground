#include <iostream>
#include <string>
#include "../../shared/Container.h"
#include "JsonHeader.cpp"
#include "JsonMenuItem.h"

using namespace std;

class JsonContainer : public Container
{
public:
	JsonContainer() : Container(
		4, 
		"Json Parser",
		"Json Parser",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~JsonContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new JsonMenuItem(logSrv));
	}

	virtual string getHeader()
	{
		JsonHeader header;
		return header.getRandomHeader();
	}

};