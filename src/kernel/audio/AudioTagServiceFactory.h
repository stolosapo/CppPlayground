#ifndef AudioTagServiceFactory_h__
#define AudioTagServiceFactory_h__

#include <iostream>
#include "../service/IService.h"
#include "../service/IServiceFactory.h"

class AudioTagServiceFactory: public IServiceFactory
{
public:
	AudioTagServiceFactory();

	IService *create();
};


#endif // AudioTagServiceFactory_h__
