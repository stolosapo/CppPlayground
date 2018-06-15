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
	/* Status tasks */
	registerTask("agent-status", &icecast_agent_status);


	/* Navigation tasks */
	registerTask("now", &icecast_now_playing);
	registerTask("start", &icecast_start);
	registerTask("stop", &icecast_stop_playing);
	registerTask("pause", &icecast_pause);
	registerTask("resume", &icecast_resume);
	registerTask("next", &icecast_next_track);


	/* Statistic tasks */
	registerTask("stats-genre", &icecast_stats_genre);
	registerTask("stats-artist", &icecast_stats_artist);
}

string IcecastAgentProtocol::help()
{
	string result = "\n";

	result += "NoiseStreamer :: Client\n";
	result += "=======================\n";
	result += "\n";
	result += "usage: <command> [<args>]\n";
	result += "\n";
	result += "These are the common NoiseStreamer commands:\n";
	result += "\n";
	result += "agent-status       See the status of the NoiseStreamer server\n";
	result += "\n";
	result += "now                See the current playing track\n";
	result += "\n";
	result += "next               Navigate to the next track\n";
	result += "\n";
	result += "stats-genre        See statistics of played genres\n";
	result += "stats-artist       See statistics of played artists\n";

	result += "\n";

	return result;
}
