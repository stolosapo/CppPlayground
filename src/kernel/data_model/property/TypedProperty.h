#ifndef TypedProperty_h__
#define TypedProperty_h__

#include "Property.h"

template <class T>
T* getTypedProperty(Property* property);


template <class T>
T* getTypedProperty(Property* property)
{
    if (property == NULL || ((T*) property) == NULL)
    {
        return NULL;
    }

    return (T*) property;
}

#endif // TypedProperty_h__
