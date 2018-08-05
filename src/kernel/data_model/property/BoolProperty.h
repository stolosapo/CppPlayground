#ifndef BoolProperty_h__
#define BoolProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyValue.h"

using namespace std;

class BoolProperty : public Property, public PropertyValue<bool>
{
public:
    BoolProperty(string name);
    virtual ~BoolProperty();

};
#endif // BoolProperty_h__
