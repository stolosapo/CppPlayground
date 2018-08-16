#include "CollectionIntJzonSerializer.h"

#include "../../../data_model/property/TypedProperty.h"
#include "../../../data_model/property/IntProperty.h"

CollectionIntJzonSerializer::CollectionIntJzonSerializer() : TypedCollectionJzonSerializer()
{

}

CollectionIntJzonSerializer::~CollectionIntJzonSerializer()
{

}

bool CollectionIntJzonSerializer::isCorrectCollectionItemType(Jzon::Node node)
{
    return node.isNumber();
}

int CollectionIntJzonSerializer::collectionItemNodeValue(Jzon::Node node)
{
    return node.toInt();
}
