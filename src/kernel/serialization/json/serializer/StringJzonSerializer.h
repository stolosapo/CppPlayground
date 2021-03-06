#ifndef StringJzonSerializer_h__
#define StringJzonSerializer_h__


#include <string>

#include "TypedValueJzonSerializer.h"
#include "../../../data_model/property/StringProperty.h"

using namespace std;

class StringJzonSerializer: public TypedValueJzonSerializer<StringProperty, string>
{
public:
    StringJzonSerializer();
    virtual ~StringJzonSerializer();

protected:
    virtual bool isCorrectType(Jzon::Node node);
    virtual void setValueToNode(Property *fromProperty, Jzon::Node *toNode, string value);
    virtual string nodeValue(Jzon::Node node);
    virtual string defaultValue();

};

#endif // StringJzonSerializer_h__
