#include "ObjectJzonSerializer.h"

#include "../../../data_model/Model.h"

ObjectJzonSerializer::ObjectJzonSerializer(JzonService* service)
    : service(service), TypedPointerJzonSerializer()
{

}

ObjectJzonSerializer::~ObjectJzonSerializer()
{

}

bool ObjectJzonSerializer::isCorrectType(Jzon::Node node)
{
    return node.isObject();
}

Jzon::Node ObjectJzonSerializer::propertyPointerValue(Model *value)
{
    return service->serializeModelToNode(value);
}

Model* ObjectJzonSerializer::nodeValue(Jzon::Node node, Property *prop)
{
    Model* value = prop->invokeModelFactory();

    service->deserializeNodeToModel(&node, value);


    return value;
}
