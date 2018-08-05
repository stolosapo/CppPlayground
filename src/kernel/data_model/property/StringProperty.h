#ifndef StringProperty_h__
#define StringProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyValue.h"

using namespace std;

class StringProperty : public Property, public PropertyValue<string>
{
public:
    StringProperty(string name);
    virtual ~StringProperty();

};
#endif // StringProperty_h__
