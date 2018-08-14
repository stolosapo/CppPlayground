#ifndef TypedPointerJzonSerializer_h__
#define TypedPointerJzonSerializer_h__

#include <iostream>
#include <string>

#include "JzonSerializer.h"
#include "../../../data_model/property/TypedProperty.h"


using namespace std;

template <class T, typename V>
class TypedPointerJzonSerializer : public JzonSerializer
{
public:
    TypedPointerJzonSerializer();
    virtual ~TypedPointerJzonSerializer();

    virtual void propertyToNode(Property *fromProperty, Jzon::Node *toNode);
    virtual void nodeToProperty(Jzon::Node *fromNode, Property *toProperty);

protected:
    virtual bool isCorrectType(Jzon::Node node) = 0;
    virtual V* nodeValue(Jzon::Node node, Property *prop) = 0;
};









template <class T, typename V>
TypedPointerJzonSerializer<T, V>::TypedPointerJzonSerializer()
{

}

template <class T, typename V>
TypedPointerJzonSerializer<T, V>::~TypedPointerJzonSerializer()
{

}

template <class T, typename V>
void TypedPointerJzonSerializer<T, V>::propertyToNode(Property *fromProperty, Jzon::Node *toNode)
{
    V* value = getTypedPropertyPointerValue<T, V>(fromProperty);

    if (value == NULL)
    {
        toNode->add(fromProperty->getName(), Jzon::null());
        return;
    }

    Jzon::Node subNode = Jzon::object();
    // serializeModelToNode(value, &subNode);
    toNode->add(fromProperty->getName(), subNode);
}

template <class T, typename V>
void TypedPointerJzonSerializer<T, V>::nodeToProperty(Jzon::Node *fromNode, Property *toProperty)
{
    Jzon::Node currentNode;
    currentNode = fromNode->get(toProperty->getName());

    if (!currentNode.isValid() || !isCorrectType(currentNode))
    {
        return;
    }

    V* value = nodeValue(currentNode, toProperty);
    if (value == NULL)
    {
        return;
    }

    setTypedPropertyPointerValue<T, V>(toProperty, value);
}


#endif // TypedPointerJzonSerializer_h__
