#include "Model.h"

#include "property/PropertyFactory.h"
#include "property/TypedProperty.h"
#include "property/IntProperty.h"
#include "property/LongProperty.h"
#include "property/DoubleProperty.h"
#include "property/StringProperty.h"
#include "property/BoolProperty.h"
#include "property/ObjectProperty.h"
#include "property/CollectionIntProperty.h"

Model::Model(ModelFactory modelFactory)
{
	this->modelFactory = modelFactory;
}


Model::~Model()
{
	for (map<string, Property*>::iterator it = allProperties.begin();
        it != allProperties.end();
        ++it)
	{
		delete it->second;
	}

	allProperties.clear();

	modelFactory = NULL;
}


bool Model::propertyNameExists(string name)
{
    map<string, Property*>::iterator it;
    it = allProperties.find(name);

    return it != allProperties.end();
}


map<string, Property*> Model::getAllProperties()
{
    return allProperties;
}


Model* Model::createNew()
{
    if (this->modelFactory == NULL)
    {
        return NULL;
    }

    return (modelFactory)();
}


void Model::registerPropertyName(int index, string name, PropertyType type)
{
    if (propertyNameExists(name))
    {
        map<string, Property*>::iterator it = allProperties.find(name);
        delete it->second;
        allProperties.erase(it);
    }

    PropertyFactory factory;

    allProperties[name] = factory.create(name, type);
}


void Model::registerPropertyName(int index, string name, PropertyType type, ModelFactory factoryMethod)
{
    if (propertyNameExists(name))
    {
        map<string, Property*>::iterator it = allProperties.find(name);
        delete it->second;
        allProperties.erase(it);
    }

    PropertyFactory factory;

    allProperties[name] = factory.create(name, factoryMethod);
}


Property* Model::getProperty(string name)
{
    if (!propertyNameExists(name))
    {
        return NULL;
    }

    return allProperties.find(name)->second;
}


int Model::getIntProperty(string name)
{
	return getIntProperty(name, 0);
}


int Model::getIntProperty(string name, int defaultValue)
{
    return getTypedPropertyValue<IntProperty, int>(getProperty(name), defaultValue);
}


long Model::getLongProperty(string name)
{
	return getLongProperty(name, 0);
}


long Model::getLongProperty(string name, long defaultValue)
{
    return getTypedPropertyValue<LongProperty, long>(getProperty(name), defaultValue);
}


double Model::getDoubleProperty(string name)
{
	return getDoubleProperty(name, 0.0);
}


double Model::getDoubleProperty(string name, double defaultValue)
{
    return getTypedPropertyValue<DoubleProperty, double>(getProperty(name), defaultValue);
}


string Model::getStringProperty(string name)
{
	return getStringProperty(name, "");
}


string Model::getStringProperty(string name, string defaultValue)
{
    return getTypedPropertyValue<StringProperty, string>(getProperty(name), defaultValue);
}


bool Model::getBoolProperty(string name)
{
	return getBoolProperty(name, false);
}


bool Model::getBoolProperty(string name, bool defaultValue)
{
	return getTypedPropertyValue<BoolProperty, bool>(getProperty(name), defaultValue);
}


Model* Model::getObjectProperty(string name)
{
    return getTypedPropertyPointerValue<ObjectProperty, Model>(getProperty(name));
}


vector<int> Model::getCollectionIntProperty(string name)
{
    return getTypedPropertyCollectionValue<CollectionIntProperty, int>(getProperty(name));
}


void Model::setIntProperty(string name, int value)
{
    setTypedPropertyValue<IntProperty, int>(getProperty(name), value);
}


void Model::setLongProperty(string name, long value)
{
    setTypedPropertyValue<LongProperty, long>(getProperty(name), value);
}


void Model::setDoubleProperty(string name, double value)
{
    setTypedPropertyValue<DoubleProperty, double>(getProperty(name), value);
}


void Model::setStringProperty(string name, string value)
{
    setTypedPropertyValue<StringProperty, string>(getProperty(name), value);
}


void Model::setBoolProperty(string name, bool value)
{
	setTypedPropertyValue<BoolProperty, bool>(getProperty(name), value);
}


void Model::setObjectProperty(string name, Model *value)
{
    setTypedPropertyPointerValue<ObjectProperty, Model>(getProperty(name), value);
}


void Model::setCollectionIntProperty(string name, vector<int> value)
{
    setTypedPropertyCollectionValue<CollectionIntProperty, int>(getProperty(name), value);
}
