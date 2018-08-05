#ifndef IntProperty_h__
#define IntProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyValue.h"

using namespace std;

class IntProperty : public Property, public PropertyValue<int>
{
public:
    IntProperty(string name);
    virtual ~IntProperty();

};
#endif // IntProperty_h__
