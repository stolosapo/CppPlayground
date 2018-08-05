#include "Property.h"

Property::Property(string name, PropertyType type)
    : name(name), type(type)
{

}

Property::~Property()
{

}

string Property::getName()
{
    return name;
}

PropertyType Property::getType()
{
    return type;
}
