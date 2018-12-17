#include "NoiseStreamerAgentTasks.h"

#include <iostream>

#include "../NoiseStreamer.h"
#include "../agent/NoiseStreamerAgent.h"
#include "../../kernel/task/TaskContext.h"
#include "../../kernel/converter/Convert.h"
#include "../../kernel/exception/ExceptionMapper.h"

using namespace std;


void* nss_agent_status(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

	double uptimeSec = a->uptime();
	int connections = a->numberOfActiveConnections();
	int numOfTracks = client->getNumberOfPlayedTracks();
	int queueSize = client->queueSize();

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
	value += "Queue Size: " + Convert<int>::NumberToString(queueSize) + "\n";

	return static_cast<void*>(new string(value));
}

void* nss_now_playing(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
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

void* nss_preview_next(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

	PlaylistItem track = client->previewNext();
    AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();

    string value = "\n";

    value += "Index: " + Convert<int>::NumberToString(index) + "\n";
    value += "Title: " + tag->getTitle() + "\n";
    value += "Artist: " + tag->getArtist() + "\n";
    value += "Album: " + tag->getAlbum() + "\n";
    value += "Genre: " + tag->getGenre() + "\n";
    value += "Duration: " + tag->getStrDuration() + "\n";
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

void* nss_start(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	return NULL;
}

void* nss_stop_playing(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	a->noiseStreamer()->stopPlaying();

	return NULL;
}

void* nss_pause(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	a->noiseStreamer()->pause();

	return NULL;
}

void* nss_resume(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	a->noiseStreamer()->resume();

	return NULL;
}

void* nss_next_track(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	a->noiseStreamer()->next();

	return NULL;
}

void* nss_request_track(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
    string indexParam = ctx->getParam(0);

    if (indexParam == "")
    {
        return NULL;
    }

    int index = Convert<int>::StringToNumber(indexParam);

    a->noiseStreamer()->requestTrack(index);

    return NULL;
}

void* nss_stats_genre(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

	string value = "\n";

	value += client->getGenreStats();

	return static_cast<void*>(new string(value));
}

void* nss_stats_artist(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

	string value = "\n";

	value += client->getArtistStats();

	return static_cast<void*>(new string(value));
}
