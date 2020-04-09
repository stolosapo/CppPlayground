#ifndef AlsaCaptureMenuItem_h__
#define AlsaCaptureMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class AlsaCaptureMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	AlsaCaptureMenuItem(ILogService *logSrv);
	virtual ~AlsaCaptureMenuItem();

	virtual void check();
	virtual void action();
};

#endif // AlsaCaptureMenuItem_h__
