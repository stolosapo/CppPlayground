#ifndef KubeConfigMenuItem_h__
#define KubeConfigMenuItem_h__

#include <string>
#include "../log/ILogService.h"
#include "../menu/MenuItem.h"

using namespace std;

class KubeConfigMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	KubeConfigMenuItem(ILogService *logSrv);
	virtual ~KubeConfigMenuItem();
	
	virtual void action();
};
#endif // KubeConfigMenuItem_h__