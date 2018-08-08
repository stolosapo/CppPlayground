#include "IntJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

IntJzonSerializer::IntJzonSerializer()
{

}

IntJzonSerializer::~IntJzonSerializer()
{

}

bool IntJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isNumber();
}

int IntJzonSerializer::nodeValue(Jzon::Node node)
{
    return node.toInt();
}
