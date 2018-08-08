#ifndef Model_h__
#define Model_h__

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "property/Property.h"
#include "property/PropertyType.h"

using namespace std;

class Model
{
private:
	map<string, Property*> allProperties;

	map<string, vector<int> > collectionIntProperties;


protected:
	typedef Model* (*staticFactoryMethod)();

	staticFactoryMethod staticFactory;
	map<string, staticFactoryMethod> propertyFactories;


	virtual void registerProperties() = 0;
	void registerPropertyName(int index, string name, PropertyType type);
	void registerPropertyName(int index, string name, PropertyType type, staticFactoryMethod factoryMethod);

    Property* getProperty(string name);

	bool propertyNameExists(string name);
	bool factoryMethodExists(string name);


public:
	Model(staticFactoryMethod staticFactory);
	virtual ~Model();

	Model* createNew();

	map<string, Property*> getAllProperties();
	Model* invokePropertyFactory(string name);

	int getIntProperty(string name);
	int getIntProperty(string name, int defaultValue);
	long getLongProperty(string name);
	long getLongProperty(string name, long defaultValue);
	double getDoubleProperty(string name);
	double getDoubleProperty(string name, double defaultValue);
	string getStringProperty(string name);
	string getStringProperty(string name, string defaultValue);
	bool getBoolProperty(string name);
	bool getBoolProperty(string name, bool defaultValue);
    Model* getObjectProperty(string name);
	vector<int> getCollectionIntProperty(string name);

	void setIntProperty(string name, int value);
	void setLongProperty(string name, long value);
	void setDoubleProperty(string name, double value);
	void setStringProperty(string name, string value);
	void setBoolProperty(string name, bool value);
    void setObjectProperty(string name, Model *value);
	void setCollectionIntProperty(string name, vector<int> value);

};
#endif // Model_h__
