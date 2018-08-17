#include "StringJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

StringJzonSerializer::StringJzonSerializer() : TypedValueJzonSerializer()
{

}

StringJzonSerializer::~StringJzonSerializer()
{

}

bool StringJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isString();
}

void StringJzonSerializer::setValueToNode(Property *fromProperty, Jzon::Node *toNode, string value)
{
    toNode->add(fromProperty->getName(), value);
}

string StringJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toString();
}

string StringJzonSerializer::defaultValue()
{
    return "";
}
