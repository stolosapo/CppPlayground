#include "NoiseStreamerAgentTasks.h"

#include <iostream>

#include "PlaylistTasks.h"
#include "../NoiseStreamer.h"
#include "../audio/PlaylistAudioSource.h"
#include "../agent/NoiseStreamerAgent.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/task/TaskContext.h"
#include "../../kernel/converter/Convert.h"
#include "../../kernel/exception/ExceptionMapper.h"
#include "../../kernel/utils/StringHelper.h"

using namespace std;


void* nss_agent_status(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

	double uptimeSec = a->uptime();
	int connections = a->numberOfActiveConnections();
    int shoutQueueLength = client->getShoutQueueLength();

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
    value += "Shout Queue Length: " + Convert<int>::NumberToString(shoutQueueLength) + "\n";

	return static_cast<void*>(new string(value));
}

void* nss_audio_status(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_audio_status(client);
    default:
        return NULL;
    }
}

void* nss_shout_status(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    NoiseStreamerConfig* config = client->getConfig();

    string value = "\n";

    value += "Version: " + client->shoutVersion() + "\n";
    value += "Error: " + client->shoutError() + "\n";

    value += "Hostname: " + config->getHostname() + "\n";
	value += "Port: " + config->getPort() + "\n";
	value += "Username: " + config->getUsername() + "\n";
	value += "Mountpoint: " + config->getMountpoint() + "\n";
	value += "Name: " + config->getName() + "\n";
	value += "Genre: " + config->getGenre() + "\n";
	value += "Description: " + config->getDescription() + "\n";
	value += "Url: " + config->getUrl() + "\n";
	value += "Bitrate: " + config->getBitrate() + "\n";
	value += "Samplerate: " + config->getSamplerate() + "\n";
	value += "Channels: " + config->getChannels() + "\n";
	value += "Strategy: " + config->getStrategy() + "\n";

    return static_cast<void*>(new string(value));
}

void* nss_now_playing(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_now_playing(client);
    default:
        return NULL;
    }
}

void* nss_preview_next(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    NoiseStreamerConfig* config = client->getConfig();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_preview_next(client);
    default:
        return NULL;
    }
}

void* nss_preview_track(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_preview_track(ctx, client);
    default:
        return NULL;
    }
}

void* nss_search(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_search(ctx, client);
    default:
        return NULL;
    }
}

void* nss_history(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_history(ctx, client);
    default:
        return NULL;
    }
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

    if (a->noiseStreamerRunning())
    {
        throw DomainException(NoiseStreamerDomainErrorCode::NSS0028);
    }

	a->startStreamer();

    return NULL;
}

void* nss_stop(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();

	a->noiseStreamer()->stop();

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
    NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_next_track(client);
    default:
        return NULL;
    }
}

void* nss_request_track(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
    NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    string indexParam = ctx->getParam(0);

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_request_track(ctx, client);
    default:
        return NULL;
    }
}

void* nss_stats_genre(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_stats_genre(client);
    default:
        return NULL;
    }
}

void* nss_stats_artist(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    AudioSource* source = client->getAudioSource();

    switch (source->getType())
    {
    case SOURCE_NONE:
        return NULL;
    case SOURCE_PLAYLIST:
        return nss_playlist_stats_artist(client);
    default:
        return NULL;
    }
}
