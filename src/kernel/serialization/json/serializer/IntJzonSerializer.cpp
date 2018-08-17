#include "IntJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

IntJzonSerializer::IntJzonSerializer() : TypedValueJzonSerializer()
{

}

IntJzonSerializer::~IntJzonSerializer()
{

}

bool IntJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isNumber();
}

void IntJzonSerializer::setValueToNode(Property *fromProperty, Jzon::Node *toNode, int value)
{
    toNode->add(fromProperty->getName(), value);
}

int IntJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toInt();
}

int IntJzonSerializer::defaultValue()
{
    return 0;
}
