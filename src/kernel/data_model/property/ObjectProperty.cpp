#include "ObjectProperty.h"

ObjectProperty::ObjectProperty(string name, ModelFactory modelFactory)
    : Property(name, OBJECT, modelFactory), PropertyPointerValue<Model>()
{

}

ObjectProperty::~ObjectProperty()
{

}
