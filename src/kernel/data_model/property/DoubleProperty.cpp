#include "DoubleProperty.h"

DoubleProperty::DoubleProperty(string name)
    : Property(name, DOUBLE), PropertyValue<double>()
{

}

DoubleProperty::~DoubleProperty()
{

}
