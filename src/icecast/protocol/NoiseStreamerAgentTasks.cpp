#include "NoiseStreamerAgentTasks.h"

#include <iostream>

#include "../NoiseStreamer.h"
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
	int numOfTracks = client->getNumberOfPlayedTracks();
    int historySize = client->historySize();
    int playlistSize = client->playlistSize();
	int queueSize = client->queueSize();
	int requestQueueSize = client->requestQueueSize();
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
    value += "Playlist Size: " + Convert<int>::NumberToString(playlistSize) + "\n";
    value += "History Size: " + Convert<int>::NumberToString(historySize) + "\n";
	value += "Number of played tracks: " + Convert<int>::NumberToString(numOfTracks) + "\n";
	value += "Playlist Queue Size: " + Convert<int>::NumberToString(queueSize) + "\n";
	value += "Request Queue Size: " + Convert<int>::NumberToString(requestQueueSize) + "\n";
	value += "Shout Queue Length: " + Convert<int>::NumberToString(shoutQueueLength) + "\n";

	return static_cast<void*>(new string(value));
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
    NoiseStreamerConfig* config = client->getConfig();

	PlaylistItem track = client->nowPlaying();
	AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();
	int remaining = client->remainingTrackTime();
	int minutes = (remaining / 60) % 60;
	int seconds = remaining % 60;
    string pathPrefix = config->getCommonTrackFilePrefix();

	char s[25];
	sprintf(s, "%02d:%02d", minutes, seconds);
	string strRemaining(s);

	string value = "\n";

    value += "Index: " + Convert<int>::NumberToString(index) + "\n";
    value += "Track: " + StringHelper::removeStart(track.getTrack(), pathPrefix) + "\n";
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
    NoiseStreamerConfig* config = client->getConfig();

	PlaylistItem track = client->previewNext();
    AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();
    string pathPrefix = config->getCommonTrackFilePrefix();

    string value = "\n";

    value += "Index: " + Convert<int>::NumberToString(index) + "\n";
    value += "Track: " + StringHelper::removeStart(track.getTrack(), pathPrefix) + "\n";
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

void* nss_preview_track(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    NoiseStreamerConfig* config = client->getConfig();
    string indexParam = ctx->getParam(0);

    if (indexParam == "")
    {
        return NULL;
    }

    int trackIndex = Convert<int>::StringToNumber(indexParam);
	PlaylistItem track = client->previewTrack(trackIndex);
    AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();
    string pathPrefix = config->getCommonTrackFilePrefix();

    string value = "\n";

    value += "Index: " + Convert<int>::NumberToString(index) + "\n";
    value += "Track: " + StringHelper::removeStart(track.getTrack(), pathPrefix) + "\n";
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

void* nss_search(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();

    string query = ctx->getParam(0);
    string strLimit = ctx->getParam(1);
    string strOffset = ctx->getParam(2);

    int limit = 5;
    int offset = 1;

    if (strLimit != "")
    {
        limit = Convert<int>::StringToNumber(strLimit);
    }

    if (strOffset != "")
    {
        offset = Convert<int>::StringToNumber(strOffset);
    }

    vector<string> results = client->searchTracks(query, limit, offset);

    string value = "\n";

    for (size_t i = 0; i < results.size(); i++)
    {
        value += results.at(i) + "\n";
    }

    return static_cast<void*>(new string(value));
}

void* nss_history(void* context)
{
    TaskContext* ctx = (TaskContext*) context;
	NoiseStreamerAgent* a = (NoiseStreamerAgent*) ctx->getData();
	NoiseStreamer* client = a->noiseStreamer();
    NoiseStreamerConfig* config = client->getConfig();

    string lengthParam = ctx->getParam(0);
    int historySize = client->historySize();
    string pathPrefix = config->getCommonTrackFilePrefix();

    if (historySize == 0)
    {
        return static_cast<void*>(new string(""));
    }

    int historyLength = 5;

    if (lengthParam != "")
    {
        int l = Convert<int>::StringToNumber(lengthParam);

        if (l < historySize)
        {
            historyLength = l;
        }
    }

    if (historyLength >= historySize)
    {
        historyLength = historySize;
    }

    string value = "\n";

    for (int i = 0; i < historyLength; i++)
    {
        int inverseIndex = (historySize - 1) - i;

        string track =  client->history(inverseIndex);
        int plsIndex = client->trackPlaylistIndex(track);

        value += Playlist::itemDescription(plsIndex, StringHelper::removeStart(track, pathPrefix)) + "\n";
    }

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
