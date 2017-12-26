#ifndef IConfig_h__
#define IConfig_h__

#include <iostream>
#include <string>

#include "../../kernel/data_model/Model.h"

using namespace std;

class IConfig : public Model
{
public:
	IConfig(staticFactoryMethod staticFactory);
	virtual ~IConfig();

};

#endif // IConfig_h__