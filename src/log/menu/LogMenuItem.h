#ifndef LogMenuItem_h__
#define LogMenuItem_h__

#include <iostream>
#include <string>
#include "../../lib/converter/Convert.h"
#include "../ILogService.h"
#include "../../menu/MenuItem.h"

using namespace std;

class LogMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	LogMenuItem(ILogService *logSrv);
	virtual ~LogMenuItem();

	virtual void action();
};
#endif // LogMenuItem_h__
