#ifndef NoiseStreamerPlaylist_h__
#define NoiseStreamerPlaylist_h__

#include "NoiseStreamerPlaylistItem.h"
#include "NoiseStreamerEncodeContext.h"
#include "../config/NoiseStreamerConfig.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/time/ITimeService.h"
#include "../../kernel/audio/playlist/PlaylistHandlerFactory.h"
#include "../../kernel/data_structure/SynchronizedQueue.h"
#include "../../kernel/data_structure/SynchronizedPQueue.h"
#include "../../kernel/task/ThreadPool.h"
#include "../../kernel/converter/Convert.h"

using namespace std;

class NoiseStreamerPlaylist
{
private:
    ILogService *logSrv;
    ITimeService* timeSrv;
    AudioEncodingService *encSrv;

    NoiseStreamerConfig* config;

    int numberOfPlayedTracks;
    PlaylistItem currentTrack;
    time_t currentTrackStartTime;

    PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;
    SynchronizedQueue<int> requestedTrackIndex;
    SynchronizedPQueue<NoiseStreamerPlaylistItem> mainQueue;
    ThreadPool* encodePool;

    void startTime();
    bool needReEncode(PlaylistItem& item);
    NoiseStreamerEncodeContext* createEncodeContext(Thread* th);

    NoiseStreamerPlaylistItem* createNssPlaylistItem(PlaylistItem item);

protected:
    void initializePlaylist(NoiseStreamerConfig* config);
    void loadPlaylist();

    bool hasNext();
    NoiseStreamerPlaylistItem* nextTrack();
    void prepareNextTrack();
    void archiveTrack(NoiseStreamerPlaylistItem* track);

public:
	NoiseStreamerPlaylist(ILogService* logSrv, ITimeService* timeSrv, AudioEncodingService *encSrv);
	virtual ~NoiseStreamerPlaylist();

    int getNumberOfPlayedTracks();
    int queueSize();

    PlaylistItem nowPlaying();
    PlaylistItem previewNext();
	int remainingTrackTime();
	string getGenreStats();
	string getArtistStats();

    void requestTrack(int index);
};

#endif // NoiseStreamerPlaylist_h__
