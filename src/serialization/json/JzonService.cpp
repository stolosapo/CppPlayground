#include <iostream>

#include "Jzon.h"
#include "JsonModel.cpp"

#include "../ISerializationService.h"

using namespace std;

class JzonService : public ISerializationService
{
private:
	void addFieldToNode(Jzon::Node *node, Model *model, Property *prop)
	{
		string name = prop->getName();
		Property::Type type = prop->getType();

		switch (type) 
		{
			case Property::INT:
				node->add(name, model->getIntProperty(name));
				break;

			case Property::LONG: 
				node->add(name, (long long) model->getLongProperty(name));
				break;

			case Property::DOUBLE: 
				node->add(name, 0.0);
				break;

			case Property::STRING: 
				node->add(name, model->getStringProperty(name));
				break;

			case Property::BOOL: 
				node->add(name, model->getBoolProperty(name));
				break;
		}
	}

	void serializeModelToNode(Model *model, Jzon::Node *node)
	{
		map<int, Property*> props = model->getAllProperties();

		for (map<int, Property*>::iterator it = props.begin(); it != props.end(); ++it)
		{
			/* Add fields */
			addFieldToNode(node, model, it->second);
		}
	}

public:
	JzonService() : ISerializationService()
	{

	}

	virtual ~JzonService()
	{

	}

	virtual string serializeModel(Model *model)
	{
		Jzon::Node node = Jzon::object();

		serializeModelToNode(model, &node);

		string result = "";
		Jzon::Writer writer;
		writer.writeString(node, result);

		return result;
	}


	virtual void deserializeModel(Model *model, string raw)
	{
		
	}

	virtual void saveModelToFile(Model *model, const string &fileName)
	{
		Jzon::Node node = Jzon::object();

		serializeModelToNode(model, &node);

		Jzon::Writer writer;
		writer.writeFile(node, fileName);
	}

	virtual void loadModelFromFile(Model *model, const string &fileName)
	{
		
	}

	void test()
	{
		testWrite();

		cout << endl << endl;

		testRead();

		cout << endl << endl;

		testModels();
	}

	void testWrite()
	{
		Jzon::Node node = Jzon::object();
		node.add("name", "value");
		node.add("number", 20);
		node.add("anothernumber", 15.3);
		node.add("bool", true);

		{
		  Jzon::Node array = Jzon::array();
		  array.add(1);
		  array.add("asdf");

		  {
		    Jzon::Node array_node = Jzon::object();
		    array_node.add("key1", "val1");
		    array_node.add("key2", "val2");
		    array.add(array_node);
		  }

		  node.add("array", array);
		}

		{
		  Jzon::Node subnode = Jzon::object();
		  subnode.add("key1", "val1");
		  subnode.add("key2", "val2");
		  node.add("subnode", subnode);
		}

		Jzon::Writer writer;
		writer.writeStream(node, cout);
	}

	void testRead()
	{
		Jzon::Parser parser;

		Jzon::Node node = parser.parseFile("test.json");

		Jzon::Writer writer;
		writer.writeStream(node, cout);
	}

	void testModels()
	{
		JsonModel *model = new JsonModel;

		model->setId(1);
		model->setName("Test Model");
		model->setDescription("This is a test model");
		model->setEnable(true);

		cout << "Id: " << model->getId() << endl;
		cout << "Name: " << model->getName() << endl;
		cout << "Description: " << model->getDescription() << endl;
		cout << "Enable: " << model->getEnable() << endl;
		cout << endl << endl;

		cout << serializeModel(model) << endl << endl;

		saveModelToFile(model, "JsonModel.json");
	}
};