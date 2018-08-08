#ifndef DoubleJzonSerializer_h__
#define DoubleJzonSerializer_h__

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/DoubleProperty.h"


class DoubleJzonSerializer: public TypedValueJzonSerializer<DoubleProperty, double>
{
public:
    DoubleJzonSerializer();
    virtual ~DoubleJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual double nodeValue(Jzon::Node node);
};

#endif // DoubleJzonSerializer_h__
