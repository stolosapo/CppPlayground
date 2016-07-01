#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
	for (map<int, Property*>::iterator it = allProperties.begin(); it != allProperties.end(); ++it)
	{
		delete it->second;
	}

	allProperties.clear();

	intProperties.clear();
	longProperties.clear();
	doubleProperties.clear();
	stringProperties.clear();
	boolProperties.clear();


	for (map<string, Model*>::iterator it = objectProperties.begin(); it != objectProperties.end(); ++it)
	{
		delete it->second;
	}

	objectProperties.clear();
}


void Model::registerPropertyName(int index, string name, Property::Type type)
{
	if (propertyNameExists(index))
	{
		allProperties.erase(allProperties.find(index));
	}

	Property *prop = new Property(name, type);

	allProperties[index] = prop;
}



string Model::getPropertyName(int index)
{
	if (!propertyNameExists(index))
	{
		return "";
	}

	Property *prop = allProperties.find(index)->second;

	return prop->getName();
}



int Model::getIntProperty(string name)
{
	if (!intPropertyExists(name))
	{
		return 0;
	}

	return intProperties.find(name)->second;
}


long Model::getLongProperty(string name)
{
	if (!longPropertyExists(name))
	{
		return 0;
	}

	return longProperties.find(name)->second;
}


double Model::getDoubleProperty(string name)
{
	if (!doublePropertyExists(name))
	{
		return 0.0;
	}

	return doubleProperties.find(name)->second;
}


string Model::getStringProperty(string name)
{
	if (!stringPropertyExists(name))
	{
		return "";
	}

	return stringProperties.find(name)->second;
}


bool Model::getBoolProperty(string name)
{
	if (!boolPropertyExists(name))
	{
		return false;
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


void Model::setIntProperty(string name, int value)
{
	if (intPropertyExists(name))
	{
		intProperties.erase(intProperties.find(name));
	}

	intProperties[name] = value;
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


bool Model::propertyNameExists(int index)
{
	map<int, Property*>::iterator it;
	it = allProperties.find(index);

	return it != allProperties.end();
}


bool Model::intPropertyExists(string name)
{
	map<string, int>::iterator it;
	it = intProperties.find(name);

	return it != intProperties.end();
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


map<int, Property*> Model::getAllProperties()
{
	return allProperties;
}