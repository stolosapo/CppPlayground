#include "Model.h"

#include "property/PropertyFactory.h"
#include "property/TypedProperty.h"
#include "property/IntProperty.h"

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

	longProperties.clear();
	doubleProperties.clear();
	stringProperties.clear();
	boolProperties.clear();


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
    IntProperty* prop = getTypedProperty<IntProperty>(getProperty(name));

    if (prop == NULL)
    {
        return defaultValue;
    }

    return prop->getValue();
}


long Model::getLongProperty(string name)
{
	return getLongProperty(name, 0);
}


long Model::getLongProperty(string name, long defaultValue)
{
	if (!longPropertyExists(name))
	{
		return defaultValue;
	}

	return longProperties.find(name)->second;
}


double Model::getDoubleProperty(string name)
{
	return getDoubleProperty(name, 0.0);
}


double Model::getDoubleProperty(string name, double defaultValue)
{
	if (!doublePropertyExists(name))
	{
		return defaultValue;
	}

	return doubleProperties.find(name)->second;
}


string Model::getStringProperty(string name)
{
	return getStringProperty(name, "");
}


string Model::getStringProperty(string name, string defaultValue)
{
	if (!stringPropertyExists(name))
	{
		return defaultValue;
	}

	return stringProperties.find(name)->second;
}


bool Model::getBoolProperty(string name)
{
	return getBoolProperty(name, false);
}


bool Model::getBoolProperty(string name, bool defaultValue)
{
	if (!boolPropertyExists(name))
	{
		return defaultValue;
	}

	return boolProperties.find(name)->second;
}


Model* Model::getObjectProperty(string name)
{
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
    IntProperty* prop = getTypedProperty<IntProperty>(getProperty(name));

    if (prop == NULL)
    {
        return;
    }

    prop->setValue(value);
}


void Model::setLongProperty(string name, long value)
{
	if (longPropertyExists(name))
	{
		longProperties.erase(longProperties.find(name));
	}

	longProperties[name] = value;
}


void Model::setDoubleProperty(string name, double value)
{
	if (doublePropertyExists(name))
	{
		doubleProperties.erase(doubleProperties.find(name));
	}

	doubleProperties[name] = value;
}


void Model::setStringProperty(string name, string value)
{
	if (stringPropertyExists(name))
	{
		stringProperties.erase(stringProperties.find(name));
	}

	stringProperties[name] = value;
}


void Model::setBoolProperty(string name, bool value)
{
	if (boolPropertyExists(name))
	{
		boolProperties.erase(boolProperties.find(name));
	}

	boolProperties[name] = value;
}


void Model::setObjectProperty(string name, Model *value)
{
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


bool Model::longPropertyExists(string name)
{
	map<string, long>::iterator it;
	it = longProperties.find(name);

	return it != longProperties.end();
}


bool Model::doublePropertyExists(string name)
{
	map<string, double>::iterator it;
	it = doubleProperties.find(name);

	return it != doubleProperties.end();
}


bool Model::stringPropertyExists(string name)
{
	map<string, string>::iterator it;
	it = stringProperties.find(name);

	return it != stringProperties.end();
}


bool Model::boolPropertyExists(string name)
{
	map<string, bool>::iterator it;
	it = boolProperties.find(name);

	return it != boolProperties.end();
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
