#ifndef ISerializationService_h__
#define ISerializationService_h__

#include <iostream>
#include <string>

#include "../data/Model.h"

using namespace std;

class ISerializationService
{
public:
	ISerializationService() { };
	virtual ~ISerializationService() { };

	virtual string serializeModel(Model *model) = 0;
	virtual void deserializeModel(Model *model, const string &raw) = 0;

	virtual void saveModelToFile(Model *model, const string &fileName) = 0;
	virtual void loadModelFromFile(Model *model, const string &fileName) = 0;

	virtual void test() = 0;
};

#endif // ISerializationService_h__