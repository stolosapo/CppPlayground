#include "IcecastAgentTasks.h"

#include <iostream>

#include "../IcecastClient.h"
#include "../IcecastAgent.h"
#include "../../kernel/converter/Convert.h"

using namespace std;

void* icecast_agent_status(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	double uptimeSec = a->uptime();
	int connections = a->numberOfActiveConnections();

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

	return static_cast<void*>(new string(value));
}

void* icecast_now_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	PlaylistItem track = client->nowPlaying();
	AudioTag* tag = track.getMetadata();

	string value = "\n";

	value += "Title: " + tag->getTitle() + "\n";
	value += "Artist: " + tag->getArtist() + "\n";
	value += "Album: " + tag->getAlbum() + "\n";
	value += "Genre: " + tag->getGenre() + "\n";
	value += "Duration: " + tag->getStrDuration() + "\n";

	return static_cast<void*>(new string(value));
}

void* icecast_start(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->action();

	return NULL;
}

void* icecast_next_track(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->nextTrack();

	return NULL;
}

void* icecast_stop_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->stopPlaying();

	return NULL;
}
