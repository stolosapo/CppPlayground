#include "StringProperty.h"

StringProperty::StringProperty(string name)
    : Property(name, STRING), PropertyValue<string>()
{

}

StringProperty::~StringProperty()
{

}
