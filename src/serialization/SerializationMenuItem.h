#ifndef SerializationMenuItem_h__
#define SerializationMenuItem_h__

#include <iostream>
#include <string>
#include "../log/ILogService.h"
#include "../menu/MenuItem.h"

using namespace std;

class SerializationMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	SerializationMenuItem(ILogService *logSrv);
	virtual ~SerializationMenuItem();
	
	virtual void action();
};
#endif // SerializationMenuItem_h__