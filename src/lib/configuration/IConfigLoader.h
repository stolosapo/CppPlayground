#ifndef IConfigLoader_h__
#define IConfigLoader_h__

#include <iostream>
#include <string>

#include "../../serialization/ISerializationService.h"
#include "../../serialization/SerializationServiceFactory.h"

using namespace std;

template<class T>
class IConfigLoader
{
private:
	ISerializationService* serializer;
	string filename;

public:
	IConfigLoader(string filename);
	virtual ~IConfigLoader();

	virtual T* load() = 0;

protected:
	ISerializationService* getSerializer();
	string getFilename();

};

#endif // IConfigLoader_h__






template<class T>
IConfigLoader<T>::IConfigLoader(string filename)
{
        this->filename = filename;

        this->serializer = SerializationServiceFactory::create();
}

template<class T>
IConfigLoader<T>::~IConfigLoader()
{
        if (this->serializer != NULL)
        {
                delete this->serializer;
        }
}

template<class T>
ISerializationService* IConfigLoader<T>::getSerializer()
{
        return this->serializer;
}

template<class T>
string IConfigLoader<T>::getFilename()
{
        return this->filename;
}
