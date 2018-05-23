#ifndef IcecastAgentMenuItem_h__
#define IcecastAgentMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class IcecastAgentMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	IcecastAgentMenuItem(ILogService *logSrv);
	virtual ~IcecastAgentMenuItem();

	virtual void check();
	virtual void action();
};

#endif // IcecastAgentMenuItem_h__
