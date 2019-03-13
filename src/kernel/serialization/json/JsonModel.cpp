#ifndef JsonModel_h__
#define JsonModel_h__

#include <iostream>
#include <string>
#include <vector>

#include "../../data_model/Model.h"

using namespace std;

class JsonModel : public Model
{
public:
	JsonModel() : Model(&factory)
	{
		registerProperties();
	}

	virtual ~JsonModel()
	{

	}


	long getId()
	{
		return getLongProperty("id");
	}

	string getName()
	{
		return getStringProperty("name");
	}

	string getDescription()
	{
		return getStringProperty("description");
	}

	double getValue()
	{
		return getDoubleProperty("value");
	}

	bool getEnable()
	{
		return getBoolProperty("enable");
	}

	JsonModel* getChild()
	{
		return (JsonModel*) getObjectProperty("child");
	}

    vector<int> getIntArray()
    {
        return getCollectionIntProperty("intArray");
    }



	void setId(long id)
	{
		setLongProperty("id", id);
	}

	void setName(string name)
	{
		setStringProperty("name", name);
	}

	void setDescription(string description)
	{
		setStringProperty("description", description);
	}

	void setValue(double value)
	{
		setDoubleProperty("value", value);
	}

	void setEnable(bool enable)
	{
		setBoolProperty("enable", enable);
	}

	void setChild(JsonModel *child)
	{
		setObjectProperty("child", child);
	}

    void setIntArray(vector<int> value)
    {
        setCollectionIntProperty("intArray", value);
    }

	static Model* factory()
	{
		return (Model*) new JsonModel;
	}


protected:
	virtual void registerProperties()
	{
		registerPropertyName(1, "id", LONG);
		registerPropertyName(2, "name", STRING);
		registerPropertyName(3, "description", STRING);
		registerPropertyName(4, "value", DOUBLE);
		registerPropertyName(5, "enable", BOOL);
        registerPropertyName(6, "child", OBJECT, &factory);
		registerPropertyName(7, "intArray", COLLECTION_INT);
	}

};

#endif // JsonModel_h__
