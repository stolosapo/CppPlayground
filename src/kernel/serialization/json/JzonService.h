#ifndef JzonService_h__
#define JzonService_h__

#include <iostream>

#include "Jzon.h"
#include "JsonModel.cpp"

#include "../ISerializationService.h"
#include "serializer/JzonSerializer.h"
#include "../../strategy/Strategy.h"
#include "../../data_model/property/PropertyType.h"

using namespace std;

class JzonService : public ISerializationService
{
private:
    Strategy<PropertyType, JzonSerializer> *serializers;

    void registerSerializers();

	void addFieldToNode(Jzon::Node *node, Model *model, Property *prop);
	void writeNodeToField(Jzon::Node *node, Model *model, Property *prop);

    void serializeModelToNode(Model *model, Jzon::Node *node);
	Jzon::Node serializeModelsToArrayNode(Model **models, int size);

	Model** deserializeArrayNodeToModels(Jzon::Node *array_node, int &size, Model *model);

public:
	JzonService();
	virtual ~JzonService();

    Jzon::Node serializeModelToNode(Model *model);
    void deserializeNodeToModel(Jzon::Node *node, Model *model);

	virtual string serializeModel(Model *model);
	virtual string serializeModels(Model **models, int size);
	virtual void deserializeModel(Model *model, const string &raw);
	virtual Model** deserializeModels(Model *model, int &size, const string &raw);
	virtual void saveModelToFile(Model *model, const string &fileName);
	virtual void saveModelsToFile(Model **models, int size, const string &fileName);
	virtual void loadModelFromFile(Model *model, const string &fileName);
	virtual Model** loadModelsFromFile(Model *model, int &size, const string &fileName);

	void test();
	void testWrite();
	void testWriteArrayToFile();
	void testRead();
	void testModels();
	void testReadModels();
	void testReadArrayModels();
};

#endif // JzonService_h__
