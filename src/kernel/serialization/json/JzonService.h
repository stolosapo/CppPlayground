#include <iostream>

#include "Jzon.h"
#include "JsonModel.cpp"

#include "../ISerializationService.h"

using namespace std;

class JzonService : public ISerializationService
{
private:
	void addFieldToNode(Jzon::Node *node, Model *model, Property *prop);

	void writeNodeToField(Jzon::Node *node, Model *model, Property *prop);

	void serializeModelToNode(Model *model, Jzon::Node *node);

	Jzon::Node serializeModelToNode(Model *model);

	Jzon::Node serializeModelsToArrayNode(Model **models, int size);

	void deserializeNodeToModel(Jzon::Node *node, Model *model);

	Model** deserializeArrayNodeToModels(Jzon::Node *array_node, int &size, Model *model);

public:
	JzonService();
	virtual ~JzonService();

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
