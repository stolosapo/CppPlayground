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

	Jzon::Node serializeModelToNode(Model *model)
	{
		Jzon::Node node = Jzon::object();

		serializeModelToNode(model, &node);

		return node;
	}

	Jzon::Node serializeModelsToArrayNode(Model **models, int size)
	{
		if (size <= 0)
		{
			return Jzon::null();
		}

		Jzon::Node array_node = Jzon::array();

		for (int i = 0; i < size; ++i)
		{
			Model *current = models[i];

			Jzon::Node currentNode = Jzon::object();

			serializeModelToNode(current, &currentNode);

			array_node.add(currentNode);
		}

		return array_node;
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

	Model** deserializeArrayNodeToModels(Jzon::Node *array_node, int &size, Model *model)
	{
		size = array_node->getCount();

		Model **array = new Model* [size];

		for (int i = 0; i < size; ++i)
		{
			Jzon::Node node = array_node->get(i);

			Model *newModel = model->createNew();

			deserializeNodeToModel(&node, newModel);

			array[i] = newModel;
		}

		return array;
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
		Jzon::Node node = serializeModelToNode(model);

		string result = "";
		Jzon::Writer writer;
		writer.writeString(node, result);

		return result;
	}


	virtual string serializeModels(Model **models, int size)
	{
		Jzon::Node array_node = serializeModelsToArrayNode(models, size);

		string result = "";
		Jzon::Writer writer;
		writer.writeString(array_node, result);

		return result;
	}


	virtual void deserializeModel(Model *model, const string &raw)
	{
		Jzon::Parser parser;
		Jzon::Node node = parser.parseString(raw);

		string error = parser.getError();

		if (error != "")
		{
			cout << error << endl;
			return;
		}
		
		deserializeNodeToModel(&node, model);
	}

	virtual Model** deserializeModels(Model *model, int &size, const string &raw)
	{
		Jzon::Parser parser;
		Jzon::Node array_node = parser.parseString(raw);

		string error = parser.getError();

		if (error != "")
		{
			cout << error << endl;
			return NULL;
		}
		
		Model **array = NULL;
		array = deserializeArrayNodeToModels(&array_node, size, model);

		return array;	
	}

	virtual void saveModelToFile(Model *model, const string &fileName)
	{
		Jzon::Node node = serializeModelToNode(model);

		Jzon::Writer writer;
		writer.writeFile(node, fileName);
	}

	virtual void saveModelsToFile(Model **models, int size, const string &fileName)
	{
		Jzon::Node array_node = serializeModelsToArrayNode(models, size);

		Jzon::Writer writer;
		writer.writeFile(array_node, fileName);
	}

	virtual void loadModelFromFile(Model *model, const string &fileName)
	{
		Jzon::Parser parser;
		Jzon::Node node = parser.parseFile(fileName);

		deserializeNodeToModel(&node, model);
	}

	virtual Model** loadModelsFromFile(Model *model, int &size, const string &fileName)
	{
		Jzon::Parser parser;
		Jzon::Node array_node = parser.parseFile(fileName);

		string error = parser.getError();

		if (error != "")
		{
			cout << error << endl;
			return NULL;
		}
		
		Model **array = NULL;
		array = deserializeArrayNodeToModels(&array_node, size, model);

		return array;	
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

		cout << endl << endl;

		testWriteArrayToFile();

		cout << endl << endl;

		testReadArrayModels();
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

	void testWriteArrayToFile()
	{
		Model **array = new Model* [2];

		JsonModel *child1 = new JsonModel;
		child1->setId(2);
		child1->setName("Test child1");
		child1->setDescription("This is a test child1");
		child1->setValue(111.999);
		child1->setEnable(false);

		JsonModel *model1 = new JsonModel;
		model1->setId(1);
		model1->setName("Test Model1");
		model1->setDescription("This is a test model1");
		model1->setValue(876.987);
		model1->setEnable(true);
		model1->setChild(child1);



		JsonModel *child2 = new JsonModel;
		child2->setId(2);
		child2->setName("Test child2");
		child2->setDescription("This is a test child2");
		child2->setValue(111.999);
		child2->setEnable(false);

		JsonModel *model2 = new JsonModel;
		model2->setId(2);
		model2->setName("Test Model2");
		model2->setDescription("This is a test model2");
		model2->setValue(876.987);
		model2->setEnable(true);
		model2->setChild(child2);

		array[0] = model1;
		array[1] = model2;

		cout << serializeModels(array, 2) << endl << endl;

		saveModelsToFile(array, 2, "JsonArrayModel.json");
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

	void testReadArrayModels()
	{
		const string json = "[{\"id\":1,\"name\":\"Test Model1\",\"description\":\"This is a test model1\",\"value\":876.987,\"enable\":true,\"child\":{\"id\":2,\"name\":\"Test child1\",\"description\":\"This is a test child1\",\"value\":111.999,\"enable\":false,\"child\":null}},{\"id\":2,\"name\":\"Test Model2\",\"description\":\"This is a test model2\",\"value\":876.987,\"enable\":true,\"child\":{\"id\":2,\"name\":\"Test child2\",\"description\":\"This is a test child2\",\"value\":111.999,\"enable\":false,\"child\":null}}]";

		JsonModel *model = new JsonModel;

		Model **array;
		int size = 0;

		array = deserializeModels(model, size, json);
		cout << serializeModels(array, size) << endl << endl;


		model = new JsonModel;
		loadModelsFromFile(model, size, "JsonArrayModel.json");
		cout << serializeModels(array, size) << endl << endl;
	}
};