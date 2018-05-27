#include "IcecastAgentProtocol.h"

#include "IcecastAgentTasks.h"


IcecastAgentProtocol::IcecastAgentProtocol(bool isServer)
	: ITcpProtocol(isServer), TaskRunner()
{
	registerTasks();
}

IcecastAgentProtocol::~IcecastAgentProtocol()
{
	
}

void IcecastAgentProtocol::registerTasks()
{
	registerTask("agent-status", &icecast_agent_status);

	registerTask("now", &icecast_now_playing);

	registerTask("start", &icecast_start);
	registerTask("next", &icecast_next_track);
	registerTask("stop", &icecast_stop_playing);
}