#include "PropertyFactory.h"

#include "IntProperty.h"
#include "LongProperty.h"
#include "DoubleProperty.h"
#include "StringProperty.h"
#include "BoolProperty.h"
#include "ObjectProperty.h"
#include "CollectionIntProperty.h"

#include "../../exception/domain/DomainException.h"
#include "../exception/DataModelErrorCode.h"

PropertyFactory::PropertyFactory()
{

}

PropertyFactory::~PropertyFactory()
{

}

Property* PropertyFactory::create(string name, PropertyType type)
{
    switch (type)
    {
        case INT:
            return (Property*) new IntProperty(name);

        case LONG:
            return (Property*) new LongProperty(name);

        case DOUBLE:
            return (Property*) new DoubleProperty(name);

        case STRING:
            return (Property*) new StringProperty(name);

        case BOOL:
            return (Property*) new BoolProperty(name);

        case OBJECT:
            throw DomainException(DataModelErrorCode::DTM0002);

        case COLLECTION_INT:
            return (Property*) new CollectionIntProperty(name);

        default:
            throw DomainException(DataModelErrorCode::DTM0001);
    }
}

Property* PropertyFactory::create(string name, ModelFactory modelFactory)
{
    return (Property*) new ObjectProperty(name, modelFactory);
}
