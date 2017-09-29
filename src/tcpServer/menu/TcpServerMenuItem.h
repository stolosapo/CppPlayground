#ifndef TcpServerMenuItem_h__
#define TcpServerMenuItem_h__

#include "../../menu/MenuItem.h"
#include "../../log/ILogService.h"

using namespace std;

class TcpServerMenuItem : public MenuItem
{
private:
        ILogService *logSrv;

public:
	TcpServerMenuItem(ILogService *logSrv);
	virtual ~TcpServerMenuItem();

	virtual void action();
};

#endif // TcpServerMenuItem_h__
