#ifndef IntJzonSerializer_h__
#define IntJzonSerializer_h__

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/IntProperty.h"


class IntJzonSerializer: public TypedValueJzonSerializer<IntProperty, int>
{
public:
    IntJzonSerializer();
    virtual ~IntJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual int nodeValue(Jzon::Node node);
};

#endif // IntJzonSerializer_h__
