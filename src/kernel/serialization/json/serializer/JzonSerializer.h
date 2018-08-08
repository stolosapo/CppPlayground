#ifndef JzonSerializer_h__
#define JzonSerializer_h__

#include <iostream>
#include <string>

#include "../Jzon.h"
#include "../../../data_model/property/Property.h"


using namespace std;

class JzonSerializer
{
public:
    JzonSerializer();
    virtual ~JzonSerializer();

    virtual void propertyToNode(Property *fromProperty, Jzon::Node *toNode) = 0;
    virtual void nodeToProperty(Jzon::Node *fromNode, Property *toProperty) = 0;
};

#endif // JzonSerializer_h__
