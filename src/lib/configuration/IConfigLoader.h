#ifndef IConfigLoader_h__
#define IConfigLoader_h__

#include <iostream>
#include <string>

#include "../../data/Model.h"

using namespace std;

template<typename T>
class IConfigLoader
{
private:
	ISerializationService serializer;
	string filename;

public:
	IConfigLoader(ISerializationService serializer, string filename);
	virtual ~IConfigLoader();

	virtual T* load();
};

#endif // IConfigLoader_h__