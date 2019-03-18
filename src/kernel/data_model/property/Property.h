#ifndef Property_h__
#define Property_h__

#include <iostream>
#include <string>

#include "PropertyType.h"
#include "../ModelFactory.h"

using namespace std;

class Property
{
private:
    string name;
    PropertyType type;
    ModelFactory modelFactory;

protected:
    Property(string name, PropertyType type);
    Property(string name, PropertyType type, ModelFactory modelFactory);

public:
    virtual ~Property();

    string getName();
    PropertyType getType();
    ModelFactory getModelFactory();

    Model* invokeModelFactory();

};
#endif // Property_h__
