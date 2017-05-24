#ifndef ITcpClient_h__
#define ITcpClient_h__

#include "../../menu/MenuItem.h"
#include "../../log/ILogService.h"

using namespace std;

class ITcpClient : public MenuItem
{
public:
	ITcpClient() : MenuItem() {};
	virtual ~ITcpClient() {};

	virtual void action() = 0;
};

#endif // ITcpClient_h__