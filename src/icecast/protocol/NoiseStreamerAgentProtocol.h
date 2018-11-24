#ifndef NoiseStreamerAgentProtocol_h__
#define NoiseStreamerAgentProtocol_h__

#include "../../kernel/tcp/protocol/ITcpProtocol.h"
#include "../../kernel/task/TaskRunner.h"

class NoiseStreamerAgentProtocol : public ITcpProtocol, public TaskRunner
{
private:
	void registerTasks();

public:
	NoiseStreamerAgentProtocol(bool isServer);
	virtual ~NoiseStreamerAgentProtocol();

	virtual string prompt();
	virtual string help();

};

#endif // NoiseStreamerAgentProtocol_h__
