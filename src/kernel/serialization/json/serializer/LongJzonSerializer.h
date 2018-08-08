#ifndef LongJzonSerializer_h__
#define LongJzonSerializer_h__

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/LongProperty.h"


class LongJzonSerializer: public TypedValueJzonSerializer<LongProperty, long long>
{
public:
    LongJzonSerializer();
    virtual ~LongJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual long long nodeValue(Jzon::Node node);
};

#endif // LongJzonSerializer_h__
