#ifndef MultiThreadServerMenuItem_h__
#define MultiThreadServerMenuItem_h__

#include "../../menu/MenuItem.h"
#include "../../log/ILogService.h"

using namespace std;

class MultiThreadServerMenuItem : public MenuItem
{
private:
        ILogService *logSrv;

public:
	MultiThreadServerMenuItem(ILogService *logSrv);
	virtual ~MultiThreadServerMenuItem();

	virtual void action();
};

#endif // MultiThreadServerMenuItem_h__
