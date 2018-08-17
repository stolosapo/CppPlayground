#ifndef TypedValueJzonSerializer_h__
#define TypedValueJzonSerializer_h__

#include <iostream>
#include <string>

#include "JzonSerializer.h"
#include "../../../data_model/property/TypedProperty.h"


using namespace std;

template <class T, typename V>
class TypedValueJzonSerializer : public JzonSerializer
{
public:
    TypedValueJzonSerializer();
    virtual ~TypedValueJzonSerializer();

    virtual void propertyToNode(Property *fromProperty, Jzon::Node *toNode);
    virtual void nodeToProperty(Jzon::Node *fromNode, Property *toProperty);

protected:
    virtual bool isCorrectType(Jzon::Node node) = 0;
    virtual V nodeValue(Jzon::Node node) = 0;
    virtual V defaultValue() = 0;
    virtual void setValueToNode(Property *fromProperty, Jzon::Node *toNode, V value) = 0;

};









template <class T, typename V>
TypedValueJzonSerializer<T, V>::TypedValueJzonSerializer()
{

}

template <class T, typename V>
TypedValueJzonSerializer<T, V>::~TypedValueJzonSerializer()
{

}

template <class T, typename V>
void TypedValueJzonSerializer<T, V>::propertyToNode(Property *fromProperty, Jzon::Node *toNode)
{
    V value = getTypedPropertyValue<T, V>(fromProperty, defaultValue());

    setValueToNode(fromProperty, toNode, value);
}

template <class T, typename V>
void TypedValueJzonSerializer<T, V>::nodeToProperty(Jzon::Node *fromNode, Property *toProperty)
{
    Jzon::Node currentNode;
    currentNode = fromNode->get(toProperty->getName());

    if (!currentNode.isValid() || !isCorrectType(currentNode))
    {
        return;
    }

    V value = nodeValue(currentNode);

    setTypedPropertyValue<T, V>(toProperty, value);
}


#endif // TypedValueJzonSerializer_h__
