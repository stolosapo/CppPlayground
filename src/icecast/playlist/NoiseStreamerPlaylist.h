#ifndef NoiseStreamerPlaylist_h__
#define NoiseStreamerPlaylist_h__

#include <signal.h>

#include "../config/NoiseStreamerConfig.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/audio/playlist/PlaylistHandlerFactory.h"
#include "../../kernel/converter/Convert.h"

using namespace std;

class NoiseStreamerPlaylist
{
private:
    ILogService *logSrv;

    PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;

protected:
    void initializePlaylist(NoiseStreamerConfig* config);
    void loadPlaylist(NoiseStreamerConfig* config);

    bool hasNext();
    PlaylistItem nextTrack();

public:
	NoiseStreamerPlaylist(ILogService* logSrv);
	virtual ~NoiseStreamerPlaylist();

    PlaylistItem nowPlaying();
	int remainingTrackTime();
	string getGenreStats();
	string getArtistStats();
};

#endif // NoiseStreamerPlaylist_h__
