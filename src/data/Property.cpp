#include "Property.h"

Property::Property(string name, Property::Type type)
{
	this->name = name;
	this->type = type;
}

Property::~Property()
{

}

string Property::getName()
{
	return name;
}

Property::Type Property::getType()
{
	return type;
}