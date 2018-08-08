#include "LongJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

LongJzonSerializer::LongJzonSerializer()
{

}

LongJzonSerializer::~LongJzonSerializer()
{

}

bool LongJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isNumber();
}

long long LongJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toInt();
}
