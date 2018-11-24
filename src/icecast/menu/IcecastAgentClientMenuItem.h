#ifndef IcecastAgentClientMenuItem_h__
#define IcecastAgentClientMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"
#include "../agent_client/IcecastAgentClient.h"

using namespace std;

class IcecastAgentClientMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

    IcecastAgentClient* clientFactory();

public:
	IcecastAgentClientMenuItem(ILogService *logSrv);
	virtual ~IcecastAgentClientMenuItem();

	virtual void check();
	virtual void action();
    virtual string help();
};

#endif // IcecastAgentClientMenuItem_h__
