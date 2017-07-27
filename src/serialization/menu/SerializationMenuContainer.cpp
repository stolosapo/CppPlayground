#include "SerializationMenuContainer.h"

#include "SerializationHeader.cpp"
#include "SerializationMenuItem.h"


SerializationMenuContainer::SerializationMenuContainer() : MenuContainer(
	4,
	"Serialization Parser",
	"Serialization Parser",
	1)
{
	this->setContinueQuestion(true);
}

SerializationMenuContainer::~SerializationMenuContainer()
{

}

void SerializationMenuContainer::fillOptions()
{
	this->addMenuItem(0, new SerializationMenuItem(logSrv));
}

string SerializationMenuContainer::getHeader()
{
	SerializationHeader header;
	return header.getRandomHeader();
}
