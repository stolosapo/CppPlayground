#ifndef ObjectJzonSerializer_h__
#define ObjectJzonSerializer_h__

#include "TypedPointerJzonSerializer.h"
#include "../../../data_model/Model.h"
#include "../../../data_model/property/ObjectProperty.h"


class ObjectJzonSerializer: public TypedPointerJzonSerializer<ObjectProperty, Model>
{
public:
    ObjectJzonSerializer();
    virtual ~ObjectJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual Model* nodeValue(Jzon::Node node, Property *prop);
};

#endif // ObjectJzonSerializer_h__
