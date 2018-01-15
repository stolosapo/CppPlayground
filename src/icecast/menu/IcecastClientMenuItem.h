#ifndef IcecastClientMenuItem_h__
#define IcecastClientMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class IcecastClientMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	IcecastClientMenuItem(ILogService *logSrv);
	virtual ~IcecastClientMenuItem();

	virtual void check();
	virtual void action();
};

#endif // IcecastClientMenuItem_h__
