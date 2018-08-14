#include "ObjectJzonSerializer.h"

#include "../../../data_model/Model.h"

ObjectJzonSerializer::ObjectJzonSerializer() : TypedPointerJzonSerializer()
{

}

ObjectJzonSerializer::~ObjectJzonSerializer()
{

}

bool ObjectJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isObject();
}

Model* ObjectJzonSerializer::nodeValue(Jzon::Node node, Property *prop)
{
    Model* value = prop->invokeModelFactory();

    // deserializeNodeToModel(&node, value);

    return value;
}
