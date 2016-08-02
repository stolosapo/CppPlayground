#include <iostream>
#include <string>

#include "SerializationHeader.cpp"
#include "SerializationMenuItem.h"

#include "../shared/Container.h"

using namespace std;

class SerializationContainer : public Container
{
public:
	SerializationContainer() : Container(
		5, 
		"Serialization Parser",
		"Serialization Parser",
		1)
	{
		this->setContinueQuestion(true);
	}

	virtual ~SerializationContainer()
	{

	}

protected:
	virtual void fillOptions()
	{
		this->addMenuItem(0, new SerializationMenuItem(logSrv));
	}

	virtual string getHeader()
	{
		SerializationHeader header;
		return header.getRandomHeader();
	}

};