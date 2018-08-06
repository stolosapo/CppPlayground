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

Model::Model(staticFactoryMethod staticFactory)
{
	this->staticFactory = staticFactory;
}


Model::~Model()
{
	for (map<string, Property*>::iterator it = allProperties.begin(); it != allProperties.end(); ++it)
	{
		delete it->second;
	}

	allProperties.clear();

	for (map<string, Model*>::iterator it = objectProperties.begin(); it != objectProperties.end(); ++it)
	{
		delete it->second;
	}

    objectProperties.clear();
    collectionIntProperties.clear();

	staticFactory = NULL;
}


void Model::registerPropertyName(int index, string name, PropertyType type)
{
	if (propertyNameExists(name))
	{
		allProperties.erase(allProperties.find(name));
	}

    PropertyFactory factory;

	allProperties[name] = factory.create(name, type);
}


void Model::registerPropertyName(int index, string name, PropertyType type, staticFactoryMethod factoryMethod)
{
	registerPropertyName(index, name, type);

	if (factoryMethodExists(name))
	{
		propertyFactories.erase(propertyFactories.find(name));
	}

	propertyFactories[name] = factoryMethod;
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
    // return getTypedPropertyPointerValue<ObjectProperty, Model>(getProperty(name));

    if (!objectPropertyExists(name))
    {
        return NULL;
    }

    return objectProperties.find(name)->second;
}


vector<int> Model::getCollectionIntProperty(string name)
{
    if (!collectionIntPropertyExists(name))
    {
        vector<int> defaultValue;
        return defaultValue;
    }

    return collectionIntProperties.find(name)->second;
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
    // setTypedPropertyPointerValue<ObjectProperty, Model>(getProperty(name), value);

	if (objectPropertyExists(name))
	{
		objectProperties.erase(objectProperties.find(name));
	}

	objectProperties[name] = value;
}


void Model::setCollectionIntProperty(string name, vector<int> value)
{
    if (collectionIntPropertyExists(name))
    {
        collectionIntProperties.erase(collectionIntProperties.find(name));
    }

    collectionIntProperties[name] = value;
}


bool Model::propertyNameExists(string name)
{
	map<string, Property*>::iterator it;
	it = allProperties.find(name);

	return it != allProperties.end();
}


bool Model::factoryMethodExists(string name)
{
	map<string, staticFactoryMethod>::iterator it;
	it = propertyFactories.find(name);

	return it != propertyFactories.end();
}


bool Model::objectPropertyExists(string name)
{
	map<string, Model*>::iterator it;
	it = objectProperties.find(name);

	return it != objectProperties.end();
}


bool Model::collectionIntPropertyExists(string name)
{
    map<string, vector<int> >::iterator it;
    it = collectionIntProperties.find(name);

    return it != collectionIntProperties.end();
}


map<string, Property*> Model::getAllProperties()
{
	return allProperties;
}


Model* Model::invokePropertyFactory(string name)
{
	if (!factoryMethodExists(name))
	{
		return NULL;
	}

	map<string, staticFactoryMethod>::iterator it;
	it = propertyFactories.find(name);

	return (*it->second)();
}


Model* Model::createNew()
{
	if (this->staticFactory == NULL)
	{
		return NULL;
	}

	return (staticFactory)();
}
