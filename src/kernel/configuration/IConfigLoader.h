#ifndef IConfigLoader_h__
#define IConfigLoader_h__

#include <iostream>
#include <string>

#include "../serialization/ISerializationService.h"
#include "../di/GlobalAppContext.h"
#include "../exception/domain/DomainException.h"
#include "../exception/domain/GeneralDomainErrorCode.h"
#include "../utils/FileHelper.h"

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

	virtual T* load();
    virtual T* createNewConfigInstance() = 0;

protected:
	ISerializationService* getSerializer();
	string getFilename();
    string getFilenameWithCheck();

};

#endif // IConfigLoader_h__






template<class T>
IConfigLoader<T>::IConfigLoader(string filename)
{
    this->filename = filename;

    this->serializer = inject<ISerializationService>("serializationService");
}

template<class T>
IConfigLoader<T>::~IConfigLoader()
{

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

template<class T>
string IConfigLoader<T>::getFilenameWithCheck()
{
    if (!FileHelper::exists(getFilename().c_str()))
    {
        throw DomainException(GeneralDomainErrorCode::GNR0001, getFilename());
    }

    return getFilename();
}

template<class T>
T* IConfigLoader<T>::load()
{
    T* config = createNewConfigInstance();

	serializer->loadModelFromFile(config, getFilenameWithCheck());

	return config;
}
