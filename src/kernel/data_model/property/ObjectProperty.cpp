#include "ObjectProperty.h"

ObjectProperty::ObjectProperty(string name)
    : Property(name, OBJECT), PropertyPointerValue<Model>()
{

}

ObjectProperty::~ObjectProperty()
{

}
