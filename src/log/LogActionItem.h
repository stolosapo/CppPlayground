#ifndef LogActionItem_h__
#define LogActionItem_h__

#include <iostream>
#include <string>
#include "../lib/converter/Convert.h"
#include "ILogService.h"
#include "../menu/MenuItem.h"

using namespace std;

class LogActionItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	LogActionItem(ILogService *logSrv);
	virtual ~LogActionItem();
	
	virtual void action();
};
#endif // LogActionItem_h__