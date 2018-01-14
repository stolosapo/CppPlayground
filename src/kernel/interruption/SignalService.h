#ifndef SignalService_h__
#define SignalService_h__

#include <iostream>
#include <string>

#include "SignalHandler.h"
#include "../service/IService.h"

using namespace std;

class SignalService: public SignalHandler, public IService
{
public:
	SignalService();
	virtual ~SignalService();

	virtual void registerSignals();
};

#endif // SignalService_h__
