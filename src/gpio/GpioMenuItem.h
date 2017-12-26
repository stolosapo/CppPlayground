#ifndef GpioMenuItem_h__
#define GpioMenuItem_h__

#include <iostream>

#include "../menu/MenuItem.h"
#include "../kernel/log/ILogService.h"

using namespace std;

class GpioMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	GpioMenuItem(ILogService *logSrv);
	virtual ~GpioMenuItem();

	virtual void action();
};

#endif // GpioMenuItem_h__
