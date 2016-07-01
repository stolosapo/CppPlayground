#ifndef Model_h__
#define Model_h__

#include <iostream>
#include <string>
#include <map>

#include "Property.h"

using namespace std;

class Model
{
private:
	map<int, Property*> allProperties;

	map<string, int> intProperties;
	map<string, long> longProperties;
	map<string, string> stringProperties;
	map<string, bool> boolProperties;
	

protected:
	virtual void registerProperties() = 0;	
	void registerPropertyName(int index, string name, Property::Type type);

	string getPropertyName(int index);

	bool propertyNameExists(int index);
	bool intPropertyExists(string name);
	bool longPropertyExists(string name);
	bool stringPropertyExists(string name);
	bool boolPropertyExists(string name);


public:
	Model();
	virtual ~Model();

	map<int, Property*> getAllProperties();

	int getIntProperty(string name);
	long getLongProperty(string name);
	string getStringProperty(string name);
	bool getBoolProperty(string name);

	void setIntProperty(string name, int value);
	void setLongProperty(string name, long value);
	void setStringProperty(string name, string value);
	void setBoolProperty(string name, bool value);

};
#endif // Model_h__