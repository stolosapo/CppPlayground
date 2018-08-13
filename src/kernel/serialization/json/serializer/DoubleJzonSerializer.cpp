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

double DoubleJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toDouble();
}
