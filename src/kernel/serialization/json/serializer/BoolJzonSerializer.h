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
    virtual bool nodeValue(Jzon::Node node);
};

#endif // BoolJzonSerializer_h__
