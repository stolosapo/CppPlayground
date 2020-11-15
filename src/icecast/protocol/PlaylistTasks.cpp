#include "PlaylistTasks.h"

#include "../audio/PlaylistAudioSource.h"
#include "../agent/NoiseStreamerAgent.h"
#include "../exception/NoiseStreamerDomainErrorCode.h"
#include "../../kernel/task/TaskContext.h"
#include "../../kernel/utils/StringHelper.h"

PlaylistAudioSource* playlist_audio_source(NoiseStreamer* client)
{
    AudioSource* source = client->getAudioSource();
    return (PlaylistAudioSource*) source;
}

void* nss_playlist_audio_status(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	int numOfTracks = playlistSource->getNumberOfPlayedTracks();
    int historySize = playlistSource->historySize();
    int playlistSize = playlistSource->playlistSize();
	int queueSize = playlistSource->queueSize();
	int requestQueueSize = playlistSource->requestQueueSize();

	string value = "\n";

    value += "Playlist Size: " + Convert<int>::NumberToString(playlistSize) + "\n";
    value += "History Size: " + Convert<int>::NumberToString(historySize) + "\n";
	value += "Number of played tracks: " + Convert<int>::NumberToString(numOfTracks) + "\n";
	value += "Playlist Queue Size: " + Convert<int>::NumberToString(queueSize) + "\n";
	value += "Request Queue Size: " + Convert<int>::NumberToString(requestQueueSize) + "\n";

	return static_cast<void*>(new string(value));
}

void* nss_playlist_now_playing(NoiseStreamer* client)
{
    NoiseStreamerConfig* config = client->getConfig();
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	PlaylistItem track = playlistSource->nowPlaying();
	AudioTag* tag = track.getMetadata();
    int index = track.getTrackIndex();
	int remaining = playlistSource->remainingTrackTime();
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

void* nss_playlist_preview_next(NoiseStreamer* client)
{
    NoiseStreamerConfig* config = client->getConfig();
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	PlaylistItem track = playlistSource->previewNext();
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

void* nss_playlist_preview_track(TaskContext* context, NoiseStreamer* client)
{
    NoiseStreamerConfig* config = client->getConfig();
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string indexParam = context->getParam(0);

    if (indexParam == "")
    {
        return NULL;
    }

    int trackIndex = Convert<int>::StringToNumber(indexParam);
	PlaylistItem track = playlistSource->previewTrack(trackIndex);
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

void* nss_playlist_search(TaskContext* context, NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string query = context->getParam(0);
    string strLimit = context->getParam(1);
    string strOffset = context->getParam(2);

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

    vector<string> results = playlistSource->searchTracks(query, limit, offset);

    string value = "\n";

    for (size_t i = 0; i < results.size(); i++)
    {
        value += results.at(i) + "\n";
    }

    return static_cast<void*>(new string(value));
}

void* nss_playlist_history(TaskContext* context, NoiseStreamer* client)
{
    NoiseStreamerConfig* config = client->getConfig();
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string lengthParam = context->getParam(0);
    int historySize = playlistSource->historySize();
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

        string track =  playlistSource->history(inverseIndex);
        int plsIndex = playlistSource->trackPlaylistIndex(track);

        value += Playlist::itemDescription(plsIndex, StringHelper::removeStart(track, pathPrefix)) + "\n";
    }

    return static_cast<void*>(new string(value));
}

void* nss_playlist_stop(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	playlistSource->stop();

	return NULL;
}

void* nss_playlist_pause(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	playlistSource->pause();

	return NULL;
}

void* nss_playlist_resume(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	playlistSource->resume();

	return NULL;
}

void* nss_playlist_next_track(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

	playlistSource->next();

	return NULL;
}

void* nss_playlist_request_track(TaskContext* context, NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string indexParam = context->getParam(0);

    if (indexParam == "")
    {
        return NULL;
    }

    int index = Convert<int>::StringToNumber(indexParam);

    playlistSource->requestTrack(index);

    return NULL;
}

void* nss_playlist_stats_genre(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string value = "\n";

	value += playlistSource->getGenreStats();

	return static_cast<void*>(new string(value));
}

void* nss_playlist_stats_artist(NoiseStreamer* client)
{
    PlaylistAudioSource* playlistSource = playlist_audio_source(client);

    string value = "\n";

	value += playlistSource->getArtistStats();

	return static_cast<void*>(new string(value));
}
