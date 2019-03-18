#include "BoolProperty.h"

BoolProperty::BoolProperty(string name)
    : Property(name, BOOL), PropertyValue<bool>()
{

}

BoolProperty::~BoolProperty()
{

}
