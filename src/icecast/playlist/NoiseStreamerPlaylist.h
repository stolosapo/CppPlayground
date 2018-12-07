#ifndef NoiseStreamerPlaylist_h__
#define NoiseStreamerPlaylist_h__

#include <signal.h>

#include "../config/NoiseStreamerConfig.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/time/ITimeService.h"
#include "../../kernel/audio/playlist/PlaylistHandlerFactory.h"
#include "../../kernel/data_structure/SynchronizedQueue.h"
#include "../../kernel/converter/Convert.h"

using namespace std;

class NoiseStreamerPlaylist
{
private:
    ILogService *logSrv;
    ITimeService* timeSrv;

    int numberOfPlayedTracks;
    PlaylistItem currentTrack;
    time_t currentTrackStartTime;

    PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;

    SynchronizedQueue<int> requestedTrackIndex;

    SynchronizedQueue<PlaylistItem> mainQueue;

    void startTime();
    int getTrackProgress();

protected:
    void initializePlaylist(NoiseStreamerConfig* config);
    void loadPlaylist(NoiseStreamerConfig* config);

    bool hasNext();
    PlaylistItem nextTrack();
    void prepateNextTrack();
    void archiveCurrentTrack();

public:
	NoiseStreamerPlaylist(ILogService* logSrv, ITimeService* timeSrv);
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
