#ifndef NoiseStreamerAgentMenuItem_h__
#define NoiseStreamerAgentMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"
#include "../agent/NoiseStreamerAgent.h"

using namespace std;

class NoiseStreamerAgentMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

    NoiseStreamerAgent* agentFactory();

public:
	NoiseStreamerAgentMenuItem(ILogService *logSrv);
	virtual ~NoiseStreamerAgentMenuItem();

	virtual void check();
	virtual void action();
    virtual string help();
};

#endif // NoiseStreamerAgentMenuItem_h__
