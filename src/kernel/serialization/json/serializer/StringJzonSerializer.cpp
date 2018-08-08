#include "StringJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

StringJzonSerializer::StringJzonSerializer()
{

}

StringJzonSerializer::~StringJzonSerializer()
{

}

bool StringJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isString();
}

string StringJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toString();
}
