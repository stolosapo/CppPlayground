#include "SerializationMenuContainer.h"

#include "SerializationHeader.cpp"
#include "SerializationMenuItem.h"


SerializationMenuContainer::SerializationMenuContainer() : MenuContainer(
	4,
	"Serialization Parser",
	"Serialization Parser")
{
	this->setContinueQuestion(true);
}

SerializationMenuContainer::~SerializationMenuContainer()
{

}

void SerializationMenuContainer::fillOptions()
{
	this->addMenuItem(new SerializationMenuItem(logSrv));
}

string SerializationMenuContainer::getHeader()
{
	SerializationHeader header;
	return header.getRandomHeader();
}
