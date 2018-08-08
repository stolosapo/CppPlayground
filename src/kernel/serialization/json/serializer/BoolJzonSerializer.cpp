#include "BoolJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

BoolJzonSerializer::BoolJzonSerializer()
{

}

BoolJzonSerializer::~BoolJzonSerializer()
{

}

bool BoolJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isBool();
}

bool BoolJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toBool();
}
