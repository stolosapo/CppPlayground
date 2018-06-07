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

string IcecastAgentProtocol::prompt()
{
	return "streamer> ";
}

void IcecastAgentProtocol::registerTasks()
{
	registerTask("agent-status", &icecast_agent_status);

	registerTask("now", &icecast_now_playing);

	registerTask("start", &icecast_start);
	registerTask("next", &icecast_next_track);
	registerTask("stop", &icecast_stop_playing);

	registerTask("stats-genre", &icecast_stats_genre);
	registerTask("stats-artist", &icecast_stats_artist);
}

string IcecastAgentProtocol::help()
{
	string result = "\n";

	result += "NoiseStreamer :: Client\n";
	result += "=======================\n\n";
	result += "usage: <command> [<args>]\n\n";
	result += "These are the common NoiseStreamer commands:\n\n";
	result += "agent-status       See the status of the NoiseStreamer server\n\n";
	result += "now                See the current playing track\n\n";
	result += "stats-genre        See statistics of played genres\n";
	result += "stats-artist       See statistics of played artists\n\n";

	return result;
}
