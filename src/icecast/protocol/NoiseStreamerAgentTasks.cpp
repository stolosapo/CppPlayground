#include "NoiseStreamerAgentTasks.h"

#include <iostream>

#include "../NoiseStreamer.h"
#include "../agent/NoiseStreamerAgent.h"
#include "../../kernel/converter/Convert.h"
#include "../../kernel/exception/ExceptionMapper.h"

using namespace std;


void* nss_agent_status(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;
	NoiseStreamer* client = a->noiseStreamer();

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

void* nss_now_playing(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;
	NoiseStreamer* client = a->noiseStreamer();

	PlaylistItem track = client->nowPlaying();
	AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();
	int remaining = client->remainingTrackTime();
	int minutes = (remaining / 60) % 60;
	int seconds = remaining % 60;

	char s[25];
	sprintf(s, "%02d:%02d", minutes, seconds);
	string strRemaining(s);

	string value = "\n";

    value += "Index: " + Convert<int>::NumberToString(index) + "\n";
	value += "Title: " + tag->getTitle() + "\n";
	value += "Artist: " + tag->getArtist() + "\n";
	value += "Album: " + tag->getAlbum() + "\n";
	value += "Genre: " + tag->getGenre() + "\n";
	value += "Duration: " + tag->getStrDuration() + "\n";
	value += "Remaining: " + strRemaining + "\n";
    value += "Bitrate: " + Convert<int>::NumberToString(tag->getBitrate()) + "\n";
    value += "Samplerate: " + Convert<int>::NumberToString(tag->getSamplerate()) + "\n";
    value += "Channels: " + Convert<int>::NumberToString(tag->getChannels()) + "\n";

	return static_cast<void*>(new string(value));
}

void* nss_start_client(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;
	ILogService* logSrv = a->logger();

	try
	{
		a->noiseStreamer()->action();
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

    a->disposeNoiseStreamer();

	return NULL;
}

void* nss_start(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;

	return NULL;
}

void* nss_stop_playing(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;

	a->noiseStreamer()->stopPlaying();

	return NULL;
}

void* nss_pause(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;

	a->noiseStreamer()->pause();

	return NULL;
}

void* nss_resume(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;

	a->noiseStreamer()->resume();

	return NULL;
}

void* nss_next_track(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;

	a->noiseStreamer()->next();

	return NULL;
}

void* nss_stats_genre(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;
	NoiseStreamer* client = a->noiseStreamer();

	string value = "\n";

	value += client->getGenreStats();

	return static_cast<void*>(new string(value));
}

void* nss_stats_artist(void* agent)
{
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) agent;
	NoiseStreamer* client = a->noiseStreamer();

	string value = "\n";

	value += client->getArtistStats();

	return static_cast<void*>(new string(value));
}
