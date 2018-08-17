#include "DoubleJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

DoubleJzonSerializer::DoubleJzonSerializer() : TypedValueJzonSerializer()
{

}

DoubleJzonSerializer::~DoubleJzonSerializer()
{

}

bool DoubleJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isNumber();
}

void DoubleJzonSerializer::setValueToNode(Property *fromProperty, Jzon::Node *toNode, double value)
{
    toNode->add(fromProperty->getName(), value);
}

double DoubleJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toDouble();
}

double DoubleJzonSerializer::defaultValue()
{
    return 0.0;
}
