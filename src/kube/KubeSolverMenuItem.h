#ifndef KubeSolverMenuItem_h__
#define KubeSolverMenuItem_h__

#include <string>
#include "../log/ILogService.h"
#include "../menu/MenuItem.h"

using namespace std;

class KubeSolverMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	KubeSolverMenuItem(ILogService *logSrv);
	virtual ~KubeSolverMenuItem();
	
	virtual void action();
};
#endif // KubeSolverMenuItem_h__