#ifndef IJsonService_cpp__
#define IJsonService_cpp__

#include <iostream>
#include <string>

#include "../data/Model.h"

using namespace std;

class IJsonService
{
public:
	IJsonService() { };
	virtual ~IJsonService() { };

	virtual string serializeModel(Model *model) = 0;
	virtual Model* deserializeModel(string raw) = 0;

	virtual void saveModelToFile(Model *model, const string &fileName) = 0;
	virtual Model* readModelFromFile(const string &fileName) = 0;

	virtual void test() = 0;
};

#endif // IJsonService_cpp__