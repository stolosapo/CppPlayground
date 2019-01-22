#include "NoiseStreamerAgentProtocol.h"

#include "NoiseStreamerAgentTasks.h"


NoiseStreamerAgentProtocol::NoiseStreamerAgentProtocol(bool isServer)
	: ITcpProtocol(isServer), TaskRunner()
{
	registerTasks();
}

NoiseStreamerAgentProtocol::~NoiseStreamerAgentProtocol()
{

}

string NoiseStreamerAgentProtocol::prompt()
{
	return "streamer> ";
}

void NoiseStreamerAgentProtocol::registerTasks()
{
	/* Status tasks */
	registerTask("agent-status", &nss_agent_status);
	registerTask("shout-status", &nss_shout_status);


	/* Navigation tasks */
	registerTask("start", &nss_start);
	registerTask("stop", &nss_stop_playing);
	registerTask("pause", &nss_pause);
	registerTask("resume", &nss_resume);
	registerTask("next", &nss_next_track);
	registerTask("request", &nss_request_track);


    /* Playlist Tasks */
    registerTask("now", &nss_now_playing);
    registerTask("preview", &nss_preview_next);
    registerTask("preview-track", &nss_preview_track);


    /* History Tasks */
    registerTask("history-info", &nss_history_info);
    registerTask("history", &nss_history);


	/* Statistic tasks */
	registerTask("stats-genre", &nss_stats_genre);
	registerTask("stats-artist", &nss_stats_artist);
}

string NoiseStreamerAgentProtocol::help()
{
	string result = "\n";

	result += "NoiseStreamer :: Client\n";
	result += "=======================\n";
	result += "\n";
	result += "usage: <command>[?<arg1>&<arg2>&<argn>]\n";
	result += "\n";
	result += "These are the common NoiseStreamer commands:\n";
	result += "\n";
	result += "agent-status                 See the status of the NoiseStreamer server\n";
	result += "shout-status                 See the status of the Shout library of the NoiseStreamer server\n";
	result += "\n";
	result += "now                          See the current playing track\n";
    result += "preview                      Preview next track\n";
    result += "preview-track?[track_index]  Preview track bu index\n";
	result += "\n";
	result += "next                         Navigate to the next track\n";
	result += "request?[track_index]        Create a track request based on track index\n";
	result += "\n";
    result += "history-info                 Return the history size\n";
    result += "history?[length=10]          Return the history of given length. Default is the last 10 tracks.\n";
    result += "\n";
	result += "stats-genre                  See statistics of played genres\n";
	result += "stats-artist                 See statistics of played artists\n";

	result += "\n";

	return result;
}
