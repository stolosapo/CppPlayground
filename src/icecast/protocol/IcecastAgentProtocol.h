#ifndef IcecastAgentProtocol_h__
#define IcecastAgentProtocol_h__

#include "../../kernel/tcp/protocol/ITcpProtocol.h"
#include "../../kernel/task/TaskRunner.h"

class IcecastAgentProtocol : public ITcpProtocol, public TaskRunner
{
private:
	void registerTasks();
	
public:
	IcecastAgentProtocol(bool isServer);
	virtual ~IcecastAgentProtocol();
	
};

#endif // IcecastAgentProtocol_h__
