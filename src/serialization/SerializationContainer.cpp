#include <iostream>
#include <string>

#include "SerializationHeader.cpp"
#include "SerializationMenuItem.h"

#include "../menu/MenuContainer.h"

using namespace std;

class SerializationContainer : public MenuContainer
{
public:
	SerializationContainer() : MenuContainer(
		4, 
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