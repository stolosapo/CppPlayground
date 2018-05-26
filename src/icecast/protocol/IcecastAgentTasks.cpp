#include "IcecastAgentTasks.h"

#include <iostream>

#include "../IcecastClient.h"
#include "../IcecastAgent.h"

using namespace std;

void* icecast_now_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;
	IcecastClient* client = a->getIcecast();

	PlaylistItem track = client->nowPlaying();
	AudioTag* tag = track.getMetadata();

	string value = "";

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
