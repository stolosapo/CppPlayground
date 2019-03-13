#ifndef LongJzonSerializer_h__
#define LongJzonSerializer_h__

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/LongProperty.h"


class LongJzonSerializer: public TypedValueJzonSerializer<LongProperty, long>
{
public:
    LongJzonSerializer();
    virtual ~LongJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual void setValueToNode(Property *fromProperty, Jzon::Node *toNode, long value);
    virtual long nodeValue(Jzon::Node node);
    virtual long defaultValue();

};

#endif // LongJzonSerializer_h__
