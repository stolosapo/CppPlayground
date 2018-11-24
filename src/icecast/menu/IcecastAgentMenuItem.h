#ifndef IcecastAgentMenuItem_h__
#define IcecastAgentMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"
#include "../agent/IcecastAgent.h"

using namespace std;

class IcecastAgentMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

    IcecastAgent* agentFactory();

public:
	IcecastAgentMenuItem(ILogService *logSrv);
	virtual ~IcecastAgentMenuItem();

	virtual void check();
	virtual void action();
    virtual string help();
};

#endif // IcecastAgentMenuItem_h__
