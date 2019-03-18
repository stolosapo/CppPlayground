#include "LongJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

LongJzonSerializer::LongJzonSerializer() : TypedValueJzonSerializer()
{

}

LongJzonSerializer::~LongJzonSerializer()
{

}

bool LongJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isNumber();
}

void LongJzonSerializer::setValueToNode(Property *fromProperty, Jzon::Node *toNode, long value)
{
    toNode->add(fromProperty->getName(), (long long) value);
}

long LongJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toInt();
}

long LongJzonSerializer::defaultValue()
{
    return 0;
}
