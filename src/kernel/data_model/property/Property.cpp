#include "Property.h"

#include "../../exception/domain/DomainException.h"
#include "../exception/DataModelErrorCode.h"

Property::Property(string name, PropertyType type)
    : name(name), type(type), modelFactory(NULL)
{

}

Property::Property(string name, PropertyType type, ModelFactory modelFactory)
    : name(name), type(type), modelFactory(modelFactory)
{

}

Property::~Property()
{

}

string Property::getName()
{
    return name;
}

PropertyType Property::getType()
{
    return type;
}

ModelFactory Property::getModelFactory()
{
    return modelFactory;
}

Model* Property::invokeModelFactory()
{
    if (modelFactory == NULL)
    {
        throw DomainException(DataModelErrorCode::DTM0003);
    }

    return modelFactory();
}
