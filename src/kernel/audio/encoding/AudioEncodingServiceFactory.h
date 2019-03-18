#ifndef AudioEncodingServiceFactory_h__
#define AudioEncodingServiceFactory_h__

#include <iostream>
#include "../../service/IService.h"
#include "../../service/IServiceFactory.h"

class AudioEncodingServiceFactory: public IServiceFactory
{
public:
	AudioEncodingServiceFactory();
    virtual ~AudioEncodingServiceFactory();

	IService *create();
};


#endif // AudioEncodingServiceFactory_h__
