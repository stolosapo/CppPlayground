#ifndef NoiseStreamerAgentClientMenuItem_h__
#define NoiseStreamerAgentClientMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"
#include "../agent_client/NoiseStreamerAgentClient.h"

using namespace std;

class NoiseStreamerAgentClientMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

    NoiseStreamerAgentClient* clientFactory();

public:
	NoiseStreamerAgentClientMenuItem(ILogService *logSrv);
	virtual ~NoiseStreamerAgentClientMenuItem();

	virtual void check();
	virtual void action();
    virtual string help();
};

#endif // NoiseStreamerAgentClientMenuItem_h__
