#ifndef NoiseStreamerPlaylist_h__
#define NoiseStreamerPlaylist_h__

#include <signal.h>

#include "../config/NoiseStreamerConfig.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/audio/playlist/PlaylistHandlerFactory.h"
#include "../../kernel/data_structure/SynchronizedQueue.h"
#include "../../kernel/converter/Convert.h"

using namespace std;

class NoiseStreamerPlaylist
{
private:
    ILogService *logSrv;

    int numberOfPlayedTracks;
    PlaylistItem currentTrack;

    PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;

    SynchronizedQueue<int> requestedTrackIndex;

    SynchronizedQueue<PlaylistItem> mainQueue;

protected:
    void initializePlaylist(NoiseStreamerConfig* config);
    void loadPlaylist(NoiseStreamerConfig* config);

    bool hasNext();
    PlaylistItem nextTrack();
    void prepateNextTrack();
    void archiveCurrentTrack();

public:
	NoiseStreamerPlaylist(ILogService* logSrv);
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
