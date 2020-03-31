#ifndef SineWaveGeneratorMenuItem_h__
#define SineWaveGeneratorMenuItem_h__

#include <iostream>

#include "../../kernel/menu/MenuItem.h"
#include "../../kernel/log/ILogService.h"

using namespace std;

class SineWaveGeneratorMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	SineWaveGeneratorMenuItem(ILogService *logSrv);
	virtual ~SineWaveGeneratorMenuItem();

	virtual void check();
	virtual void action();
    // virtual string help();
};

#endif // SineWaveGeneratorMenuItem_h__
