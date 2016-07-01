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

	bool getEnable()
	{
		return getBoolProperty("enable");
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

	void setEnable(bool enable)
	{
		setBoolProperty("enable", enable);
	}


protected:
	virtual void registerProperties()
	{
		registerPropertyName(1, "id", Property::LONG);
		registerPropertyName(2, "name", Property::STRING);
		registerPropertyName(3, "description", Property::STRING);
		registerPropertyName(4, "enable", Property::BOOL);
	}

};