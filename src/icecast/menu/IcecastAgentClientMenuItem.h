#ifndef IcecastAgentClientMenuItem_h__
#define IcecastAgentClientMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class IcecastAgentClientMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	IcecastAgentClientMenuItem(ILogService *logSrv);
	virtual ~IcecastAgentClientMenuItem();

	virtual void check();
	virtual void action();
};

#endif // IcecastAgentClientMenuItem_h__
