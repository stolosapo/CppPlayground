#ifndef EntityModel_h__
#define EntityModel_h__

#include <iostream>
#include <string>
#include <map>

#include "Model.h"

using namespace std;

class EntityModel : public Model
{
protected:
	virtual void registerProperties() = 0;
	virtual string registerTableName() = 0;


public:
	EntityModel(staticFactoryMethod staticFactory);
	virtual ~EntityModel();

	string getTableName();

};
#endif // EntityModel_h__