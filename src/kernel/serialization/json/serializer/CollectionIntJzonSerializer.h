#ifndef CollectionIntJzonSerializer_h__
#define CollectionIntJzonSerializer_h__

#include "TypedCollectionJzonSerializer.h"
#include "../../../data_model/property/CollectionIntProperty.h"


class CollectionIntJzonSerializer: public TypedCollectionJzonSerializer<CollectionIntProperty, int>
{
public:
    CollectionIntJzonSerializer();
    virtual ~CollectionIntJzonSerializer();

protected:
    virtual bool isCorrectCollectionItemType(Jzon::Node node);
    virtual int collectionItemNodeValue(Jzon::Node node);
};

#endif // CollectionIntJzonSerializer_h__
