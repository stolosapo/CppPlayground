#include "BoolJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

BoolJzonSerializer::BoolJzonSerializer() : TypedValueJzonSerializer()
{

}

BoolJzonSerializer::~BoolJzonSerializer()
{

}

bool BoolJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isBool();
}

void BoolJzonSerializer::setValueToNode(Property *fromProperty, Jzon::Node *toNode, bool value)
{
    toNode->add(fromProperty->getName(), value);
}

bool BoolJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toBool();
}

bool BoolJzonSerializer::defaultValue()
{
    return false;
}
