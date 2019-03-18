#ifndef TypedCollectionJzonSerializer_h__
#define TypedCollectionJzonSerializer_h__

#include <iostream>
#include <string>
#include <vector>

#include "JzonSerializer.h"
#include "../../../data_model/property/TypedProperty.h"


using namespace std;

template <class T, typename V>
class TypedCollectionJzonSerializer : public JzonSerializer
{
public:
    TypedCollectionJzonSerializer();
    virtual ~TypedCollectionJzonSerializer();

    virtual void propertyToNode(Property *fromProperty, Jzon::Node *toNode);
    virtual void nodeToProperty(Jzon::Node *fromNode, Property *toProperty);

protected:
    virtual bool isCorrectCollectionItemType(Jzon::Node node) = 0;
    virtual V collectionItemNodeValue(Jzon::Node node) = 0;

};









template <class T, typename V>
TypedCollectionJzonSerializer<T, V>::TypedCollectionJzonSerializer()
{

}

template <class T, typename V>
TypedCollectionJzonSerializer<T, V>::~TypedCollectionJzonSerializer()
{

}

template <class T, typename V>
void TypedCollectionJzonSerializer<T, V>::propertyToNode(Property *fromProperty, Jzon::Node *toNode)
{
    vector<V> value = getTypedPropertyCollectionValue<T, V>(fromProperty);

    Jzon::Node arrayNode = Jzon::array();
    for (vector<int>::iterator it = value.begin(); it != value.end(); ++it)
    {
        arrayNode.add(*it);
    }

    toNode->add(fromProperty->getName(), arrayNode);
}

template <class T, typename V>
void TypedCollectionJzonSerializer<T, V>::nodeToProperty(Jzon::Node *fromNode, Property *toProperty)
{
    Jzon::Node currentNode;
    currentNode = fromNode->get(toProperty->getName());

    if (!currentNode.isValid() || !currentNode.isArray())
    {
        return;
    }

    vector<V> value;
    for (int i = 0; i < currentNode.getCount(); ++i)
    {
        Jzon::Node n = currentNode.get(i);
        if (n.isValid() && isCorrectCollectionItemType(n))
        {
            value.push_back(collectionItemNodeValue(n));
        }
    }

    setTypedPropertyCollectionValue<T, V>(toProperty, value);
}


#endif // TypedCollectionJzonSerializer_h__
