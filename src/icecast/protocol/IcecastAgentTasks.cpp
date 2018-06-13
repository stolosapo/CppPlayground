#include "IcecastAgentTasks.h"

#include <iostream>

#include "../IcecastClient.h"
#include "../IcecastAgent.h"
#include "../../kernel/converter/Convert.h"
#include "../../kernel/exception/ExceptionMapper.h"

using namespace std;

void* icecast_help(void* agent)
{

}

void* icecast_agent_status(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	double uptimeSec = a->uptime();
	int connections = a->numberOfActiveConnections();
	int numOfTracks = client->getNumberOfPlayedTracks();

	int sec = uptimeSec;

	int days = sec / 60 / 60 / 24;
	int hours = (sec / 60 / 60) % 24;
	int minutes = (sec / 60) % 60;
	int seconds = sec % 60;

	char s[25];
	sprintf(s, "%01d days, %02d:%02d:%02d", days, hours, minutes, seconds);
	string str(s);

	string value = "\n";

	value += "Version: " + string(client->version()) + "\n";
	value += "Uptime: " + str + "\n";
	value += "Active connections: " + Convert<int>::NumberToString(connections) + "\n";
	value += "Number of played tracks: " + Convert<int>::NumberToString(numOfTracks) + "\n";

	return static_cast<void*>(new string(value));
}

void* icecast_now_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	PlaylistItem track = client->nowPlaying();
	AudioTag* tag = track.getMetadata();
	int remaining = client->remainingTrackTime();
	int minutes = (remaining / 60) % 60;
	int seconds = remaining % 60;

	char s[25];
	sprintf(s, "%02d:%02d", minutes, seconds);
	string strRemaining(s);

	string value = "\n";

	value += "Title: " + tag->getTitle() + "\n";
	value += "Artist: " + tag->getArtist() + "\n";
	value += "Album: " + tag->getAlbum() + "\n";
	value += "Genre: " + tag->getGenre() + "\n";
	value += "Duration: " + tag->getStrDuration() + "\n";
	value += "Remaining: " + strRemaining + "\n";

	return static_cast<void*>(new string(value));
}

void* icecast_start(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	ILogService* logSrv = a->logger();

	try
	{
		a->getIcecast()->action();
	}
	catch(DomainException& e)
	{
		logSrv->error(handle(e));
	}
	catch(RuntimeException& e)
	{
		logSrv->error(handle(e));
	}
	catch(exception& e)
	{
		logSrv->error(e.what());
	}

	return NULL;
}

void* icecast_next_track(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->next();

	return NULL;
}

void* icecast_stop_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->stopPlaying();

	return NULL;
}

void* icecast_pause(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->pause();

	return NULL;
}

void* icecast_resume(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->resume();

	return NULL;
}

void* icecast_stats_genre(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	string value = "\n";

	value += client->getGenreStats();

	return static_cast<void*>(new string(value));
}

void* icecast_stats_artist(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	string value = "\n";

	value += client->getArtistStats();

	return static_cast<void*>(new string(value));
}
