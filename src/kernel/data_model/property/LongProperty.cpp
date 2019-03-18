#include "LongProperty.h"

LongProperty::LongProperty(string name)
    : Property(name, LONG), PropertyValue<long>()
{

}

LongProperty::~LongProperty()
{

}
