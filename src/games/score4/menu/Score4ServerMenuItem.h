#ifndef Score4ServerMenuItem_h__
#define Score4ServerMenuItem_h__

#include <iostream>
#include <string>
#include "../../../kernel/log/ILogService.h"
#include "../../../kernel/menu/MenuItem.h"

using namespace std;

class Score4ServerMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	Score4ServerMenuItem(ILogService *logSrv);
	virtual ~Score4ServerMenuItem();

	virtual void action();
};
#endif // Score4ServerMenuItem_h__
