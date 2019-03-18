#ifndef SignalServiceFactory_h__
#define SignalServiceFactory_h__

#include "SignalService.h"
#include "../service/IServiceFactory.h"

class SignalServiceFactory: public IServiceFactory
{
public:
	SignalServiceFactory();
	virtual ~SignalServiceFactory();

	IService *create();
};


#endif // SignalServiceFactory_h__
