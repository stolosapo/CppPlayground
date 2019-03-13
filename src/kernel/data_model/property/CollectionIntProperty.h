#ifndef CollectionIntProperty_h__
#define CollectionIntProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyCollectionValue.h"

using namespace std;

class CollectionIntProperty : public Property, public PropertyCollectionValue<int>
{
public:
    CollectionIntProperty(string name);
    virtual ~CollectionIntProperty();

};
#endif // CollectionIntProperty_h__
