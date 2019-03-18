#ifndef ConfigLoader_h__
#define ConfigLoader_h__

#include <iostream>
#include <string>

#include "../serialization/ISerializationService.h"
#include "../di/GlobalAppContext.h"
#include "../exception/domain/DomainException.h"
#include "../exception/domain/GeneralDomainErrorCode.h"
#include "../utils/FileHelper.h"

using namespace std;

template<class T>
class ConfigLoader
{
private:
	ISerializationService* serializer;
	string filename;

public:
	ConfigLoader(string filename);
	virtual ~ConfigLoader();

	virtual T* load();

protected:
	ISerializationService* getSerializer();
	string getFilename();
    string getFilenameWithCheck();

};

#endif // ConfigLoader_h__






template<class T>
ConfigLoader<T>::ConfigLoader(string filename)
{
    this->filename = filename;

    this->serializer = inject<ISerializationService>("serializationService");
}

template<class T>
ConfigLoader<T>::~ConfigLoader()
{

}

template<class T>
ISerializationService* ConfigLoader<T>::getSerializer()
{
    return this->serializer;
}

template<class T>
string ConfigLoader<T>::getFilename()
{
    return this->filename;
}

template<class T>
string ConfigLoader<T>::getFilenameWithCheck()
{
    if (!FileHelper::exists(filename.c_str()))
    {
        throw DomainException(GeneralDomainErrorCode::GNR0001, filename);
    }

    return filename;
}

template<class T>
T* ConfigLoader<T>::load()
{
    T c;
    T* config = (T*) c.createNew();

	serializer->loadModelFromFile(config, getFilenameWithCheck());

	return config;
}
