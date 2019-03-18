#ifndef TestKubeNotationMenuItem_h__
#define TestKubeNotationMenuItem_h__

#include <string>
#include "../../kernel/log/ILogService.h"
#include "../../kernel/menu/MenuItem.h"

using namespace std;

class TestKubeNotationMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	TestKubeNotationMenuItem(ILogService *logSrv);
	virtual ~TestKubeNotationMenuItem();

	virtual void action();
};
#endif // TestKubeNotationMenuItem_h__
