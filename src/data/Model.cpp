#include "Model.h"

Model::Model()
{

}

Model::~Model()
{
	allProperties.clear();

	intProperties.clear();
	longProperties.clear();
	stringProperties.clear();
	boolProperties.clear();
}


void Model::registerPropertyName(int index, string name)
{
	if (propertyNameExists(index))
	{
		allProperties.erase(allProperties.find(index));
	}

	allProperties[index] = name;
}


string Model::getPropertyName(int index)
{
	if (!propertyNameExists(index))
	{
		return "";
	}

	return allProperties.find(index)->second;
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



bool Model::propertyNameExists(int index)
{
	map<int, string>::iterator it;
	it = allProperties.find(index);

	return it == allProperties.end();
}



bool Model::intPropertyExists(string name)
{
	map<string, int>::iterator it;
	it = intProperties.find(name);

	return it == intProperties.end();
}



bool Model::longPropertyExists(string name)
{
	map<string, long>::iterator it;
	it = longProperties.find(name);

	return it == longProperties.end();
}



bool Model::stringPropertyExists(string name)
{
	map<string, string>::iterator it;
	it = stringProperties.find(name);

	return it == stringProperties.end();
}



bool Model::boolPropertyExists(string name)
{
	map<string, bool>::iterator it;
	it = boolProperties.find(name);

	return it == boolProperties.end();
}



map<int, string> Model::getAllProperties()
{
	return allProperties;
}



map<string, int> Model::getIntProperties()
{
	return intProperties;
}



map<string, long> Model::getLongProperties()
{
	return longProperties;
}



map<string, string> Model::getStringProperties()
{
	return stringProperties;
}



map<string, bool> Model::getBoolProperties()
{
	return boolProperties;
}

