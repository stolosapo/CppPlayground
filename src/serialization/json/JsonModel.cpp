#include <iostream>
#include <string>

#include "../../data/Model.h"
#include "../../data/Property.h"

using namespace std;

class JsonModel : public Model
{
public:
	JsonModel() : Model()
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


protected:
	virtual void registerProperties()
	{
		registerPropertyName(1, "id", Property::LONG);
		registerPropertyName(2, "name", Property::STRING);
		registerPropertyName(3, "description", Property::STRING);
		registerPropertyName(4, "value", Property::DOUBLE);
		registerPropertyName(5, "enable", Property::BOOL);
		registerPropertyName(6, "child", Property::OBJECT);
	}

};