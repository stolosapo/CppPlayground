#ifndef IConfig_h__
#define IConfig_h__

#include <iostream>
#include <string>

#include "../../data/Model.h"

using namespace std;

class IConfig : public Model
{
private:
	string fileName;
	
public:
	IConfig(string fileName, staticFactoryMethod staticFactory);
	virtual ~IConfig();

};

#endif // IConfig_h__