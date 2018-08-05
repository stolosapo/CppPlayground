#include "IntProperty.h"

IntProperty::IntProperty(string name)
    : Property(name, INT), PropertyValue<int>()
{

}

IntProperty::~IntProperty()
{

}
