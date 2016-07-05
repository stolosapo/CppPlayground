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
				node->add(name, model->getDoubleProperty(name));
				break;

			case Property::STRING: 
				node->add(name, model->getStringProperty(name));
				break;

			case Property::BOOL: 
				node->add(name, model->getBoolProperty(name));
				break;

			case Property::OBJECT:

				Model *subObject = model->getObjectProperty(name);
				if (subObject != NULL)
				{
					Jzon::Node subNode = Jzon::object();
					serializeModelToNode(model->getObjectProperty(name), &subNode);
					node->add(name, subNode);
				}
				else
				{
					node->add(name, Jzon::null());
				}
				
				break;
		}
	}

	void writeNodeToField(Jzon::Node *node, Model *model, Property *prop)
	{
		string name = prop->getName();

		/* Check if this node exists */
		if (!node->has(name))
		{
			return;
		}

		Property::Type type = prop->getType();

		Jzon::Node currentNode;
		currentNode = node->get(name);

		/* Check if current node is valid */
		if (!currentNode.isValid())
		{
			return;
		}

		switch (type)
		{
			case Property::INT:
				if (currentNode.isNumber())
				{
					model->setIntProperty(name, currentNode.toInt());
				}
				break;

			case Property::LONG:
				if (currentNode.isNumber())
				{
					model->setLongProperty(name, (long) currentNode.toInt());
				}
				break;

			case Property::DOUBLE: 
				if (currentNode.isNumber())
				{
					model->setDoubleProperty(name, currentNode.toDouble());
				}
				break;

			case Property::STRING:
				if (currentNode.isString())
				{
					model->setStringProperty(name, currentNode.toString());
				}
				break;

			case Property::BOOL:
				if (currentNode.isBool())
				{
					model->setBoolProperty(name, currentNode.toBool());
				}
				break;

			case Property::OBJECT:
				if (currentNode.isObject())
				{
					Model *child = model->invokePropertyFactory(name);
					if (child != NULL)
					{
						deserializeNodeToModel(&currentNode, child);
					}

					model->setObjectProperty(name, child);
				}
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

	void deserializeNodeToModel(Jzon::Node *node, Model *model)
	{
		map<int, Property*> props = model->getAllProperties();

		for (map<int, Property*>::iterator it = props.begin(); it != props.end(); ++it)
		{
			/* Write each fields */
			writeNodeToField(node, model, it->second);
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


	virtual void deserializeModel(Model *model, const string &raw)
	{
		Jzon::Parser parser;
		Jzon::Node node = parser.parseString(raw);

		string error = parser.getError();

		if (error == "")
		{
			deserializeNodeToModel(&node, model);
		}
		else
		{
			cout << error << endl;
		}		
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
		Jzon::Parser parser;
		Jzon::Node node = parser.parseFile(fileName);

		deserializeNodeToModel(&node, model);
	}

	void test()
	{
		testWrite();

		cout << endl << endl;

		testRead();

		cout << endl << endl;

		testModels();

		cout << endl << endl;

		testReadModels();
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
		JsonModel *child = new JsonModel;
		child->setId(2);
		child->setName("Test child");
		child->setDescription("This is a test child");
		child->setValue(111.999);
		child->setEnable(false);

		JsonModel *model = new JsonModel;
		model->setId(1);
		model->setName("Test Model");
		model->setDescription("This is a test model");
		model->setValue(876.987);
		model->setEnable(true);
		model->setChild(child);

		cout << "Id: " << model->getId() << endl;
		cout << "Name: " << model->getName() << endl;
		cout << "Description: " << model->getDescription() << endl;
		cout << "Value: " << model->getValue() << endl;
		cout << "Enable: " << model->getEnable() << endl;
		cout << "Child: " << model->getChild() << endl;
		cout << endl << endl;

		cout << serializeModel(model) << endl << endl;

		saveModelToFile(model, "JsonModel.json");
	}

	void testReadModels()
	{
		const string json = "{\"id\":1,\"name\":\"Test Model\",\"description\":\"This is a test model\",\"value\":876.987,\"enable\":true,\"child\":{\"id\":2,\"name\":\"Test child\",\"description\":\"This is a test child\",\"value\":111.999,\"enable\":false,\"child\":null}}";

		JsonModel *model = new JsonModel;
		deserializeModel(model, json);
		cout << serializeModel(model) << endl << endl;


		model = new JsonModel;
		loadModelFromFile(model, "JsonModel.json");
		cout << serializeModel(model) << endl << endl;
	}
};