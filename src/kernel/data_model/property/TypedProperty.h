#ifndef TypedProperty_h__
#define TypedProperty_h__

#include "Property.h"
#include "PropertyValue.h"
#include "PropertyPointerValue.h"
#include "PropertyCollectionValue.h"

template <class T>
T* getTypedProperty(Property* property);


template <class T, typename V>
V getTypedPropertyValue(Property* property, V defaultValue);

template <class T, typename V>
V* getTypedPropertyPointerValue(Property* property);

template <class T, typename V>
vector<V> getTypedPropertyCollectionValue(Property* property);


template <class T, typename V>
void setTypedPropertyValue(Property* property, V value);

template <class T, typename V>
void setTypedPropertyPointerValue(Property* property, V* value);

template <class T, typename V>
void setTypedPropertyCollectionValue(Property* property, vector<V> value);




template <class T>
T* getTypedProperty(Property* property)
{
    if (property == NULL || ((T*) property) == NULL)
    {
        return NULL;
    }

    return (T*) property;
}



template <class T, typename V>
V getTypedPropertyValue(Property* property, V defaultValue)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyValue<V>*) prop == NULL)
    {
        return defaultValue;
    }

    PropertyValue<V>* propValue = (PropertyValue<V>*) prop;

    return propValue->getValue();
}

template <class T, typename V>
V* getTypedPropertyPointerValue(Property* property)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyPointerValue<V>*) prop == NULL)
    {
        return NULL;
    }

    PropertyPointerValue<V>* propValue = (PropertyPointerValue<V>*) prop;

    return propValue->getValue();
}

template <class T, typename V>
vector<V> getTypedPropertyCollectionValue(Property* property)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyCollectionValue<V>*) prop == NULL)
    {
        vector<V> v;
        return v;
    }

    PropertyCollectionValue<V>* propValue = (PropertyCollectionValue<V>*) prop;

    return propValue->getValue();
}



template <class T, typename V>
void setTypedPropertyValue(Property* property, V value)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyValue<V>*) prop == NULL)
    {
        return;
    }

    PropertyValue<V>* propValue = (PropertyValue<V>*) prop;

    propValue->setValue(value);
}

template <class T, typename V>
void setTypedPropertyPointerValue(Property* property, V* value)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyPointerValue<V>*) prop == NULL)
    {
        return;
    }

    PropertyPointerValue<V>* propValue = (PropertyPointerValue<V>*) prop;

    propValue->setValue(value);
}

template <class T, typename V>
void setTypedPropertyCollectionValue(Property* property, vector<V> value)
{
    T* prop = getTypedProperty<T>(property);

    if (prop == NULL || (PropertyCollectionValue<V>*) prop == NULL)
    {
        return;
    }

    PropertyCollectionValue<V>* propValue = (PropertyCollectionValue<V>*) prop;

    propValue->setValue(value);
}

#endif // TypedProperty_h__
