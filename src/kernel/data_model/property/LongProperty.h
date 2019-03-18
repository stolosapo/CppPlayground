#ifndef LongProperty_h__
#define LongProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyValue.h"

using namespace std;

class LongProperty : public Property, public PropertyValue<long>
{
public:
    LongProperty(string name);
    virtual ~LongProperty();

};
#endif // LongProperty_h__
