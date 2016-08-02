#ifndef Model_h__
#define Model_h__

#include <iostream>
#include <string>
#include <map>

#include "Property.h"
#include "Event.h"

using namespace std;

class Model
{
private:
	map<int, Property*> allProperties;

	map<string, int> intProperties;
	map<string, long> longProperties;
	map<string, double> doubleProperties;
	map<string, string> stringProperties;
	map<string, bool> boolProperties;
	map<string, Model*> objectProperties;
	

protected:
	typedef Model* (*staticFactoryMethod)();

	staticFactoryMethod staticFactory;
	map<string, staticFactoryMethod> propertyFactories;
	

	virtual void registerProperties() = 0;	
	void registerPropertyName(int index, string name, Property::Type type);
	void registerPropertyName(int index, string name, Property::Type type, staticFactoryMethod factoryMethod);

	string getPropertyName(int index);

	bool propertyNameExists(int index);
	bool factoryMethodExists(string name);

	bool intPropertyExists(string name);
	bool longPropertyExists(string name);
	bool doublePropertyExists(string name);
	bool stringPropertyExists(string name);
	bool boolPropertyExists(string name);
	bool objectPropertyExists(string name);


public:
	Model(staticFactoryMethod staticFactory);
	virtual ~Model();

	Model* createNew();

	map<int, Property*> getAllProperties();
	Model* invokePropertyFactory(string name);

	int getIntProperty(string name);
	long getLongProperty(string name);
	double getDoubleProperty(string name);
	string getStringProperty(string name);
	bool getBoolProperty(string name);
	Model* getObjectProperty(string name);

	void setIntProperty(string name, int value);
	void setLongProperty(string name, long value);
	void setDoubleProperty(string name, double value);
	void setStringProperty(string name, string value);
	void setBoolProperty(string name, bool value);
	void setObjectProperty(string name, Model *value);

};
#endif // Model_h__