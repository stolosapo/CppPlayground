#ifndef JsonMenuItem_h__
#define JsonMenuItem_h__

#include <iostream>
#include <string>
#include "../log/ILogService.h"
#include "../menu/MenuItem.h"

using namespace std;

class JsonMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	JsonMenuItem(ILogService *logSrv);
	virtual ~JsonMenuItem();
	
	virtual void action();
};
#endif // JsonMenuItem_h__