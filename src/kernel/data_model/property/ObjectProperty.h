#ifndef ObjectProperty_h__
#define ObjectProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyPointerValue.h"
#include "../Model.h"

using namespace std;

class ObjectProperty : public Property, public PropertyPointerValue<Model>
{
public:
    ObjectProperty(string name, ModelFactory modelFactory);
    virtual ~ObjectProperty();

};
#endif // ObjectProperty_h__
