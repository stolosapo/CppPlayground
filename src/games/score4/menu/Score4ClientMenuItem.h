#ifndef Score4ClientMenuItem_h__
#define Score4ClientMenuItem_h__

#include <iostream>
#include <string>
#include "../../../kernel/log/ILogService.h"
#include "../../../kernel/menu/MenuItem.h"

using namespace std;

class Score4ClientMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	Score4ClientMenuItem(ILogService *logSrv);
	virtual ~Score4ClientMenuItem();

	virtual void action();
};
#endif // Score4ClientMenuItem_h__
