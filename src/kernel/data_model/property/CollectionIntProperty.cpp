#include "CollectionIntProperty.h"

CollectionIntProperty::CollectionIntProperty(string name)
    : Property(name, COLLECTION_INT), PropertyCollectionValue<int>()
{

}

CollectionIntProperty::~CollectionIntProperty()
{

}
