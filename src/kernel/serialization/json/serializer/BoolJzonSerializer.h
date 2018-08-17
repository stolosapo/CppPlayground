#ifndef BoolJzonSerializer_h__
#define BoolJzonSerializer_h__

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/BoolProperty.h"


class BoolJzonSerializer: public TypedValueJzonSerializer<BoolProperty, bool>
{
public:
    BoolJzonSerializer();
    virtual ~BoolJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual void setValueToNode(Property *fromProperty, Jzon::Node *toNode, bool value);
    virtual bool nodeValue(Jzon::Node node);
    virtual bool defaultValue();

};

#endif // BoolJzonSerializer_h__
