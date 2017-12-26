#ifndef TcpClientMenuItem_h__
#define TcpClientMenuItem_h__

#include "../../menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class TcpClientMenuItem : public MenuItem
{
private:
        ILogService *logSrv;

public:
	TcpClientMenuItem(ILogService *logSrv);
	virtual ~TcpClientMenuItem();

	virtual void action();
};

#endif // TcpClientMenuItem_h__
