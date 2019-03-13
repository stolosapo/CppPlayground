#ifndef DoubleProperty_h__
#define DoubleProperty_h__

#include <iostream>
#include <string>

#include "Property.h"
#include "PropertyValue.h"

using namespace std;

class DoubleProperty : public Property, public PropertyValue<double>
{
public:
    DoubleProperty(string name);
    virtual ~DoubleProperty();

};
#endif // DoubleProperty_h__
