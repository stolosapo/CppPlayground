#ifndef PropertyFactory_h__
#define PropertyFactory_h__

#include <iostream>
#include <string>

#include "Property.h"

using namespace std;

class PropertyFactory
{
public:
    PropertyFactory();
    virtual ~PropertyFactory();

    Property* create(string name, PropertyType type);
    Property* create(string name, ModelFactory modelFactory);

};
#endif // PropertyFactory_h__
