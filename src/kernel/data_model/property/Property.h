#ifndef Property_h__
#define Property_h__

#include <iostream>
#include <string>

#include "PropertyType.h"

using namespace std;

class Property
{
private:
    string name;
    PropertyType type;

protected:
    Property(string name, PropertyType type);

public:
    virtual ~Property();

    string getName();
    PropertyType getType();

};
#endif // Property_h__
