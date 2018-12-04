#ifndef NoiseStreamer_h__
#define NoiseStreamer_h__

#include "NoiseStreamerNavigator.h"
#include "config/NoiseStreamerConfig.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "../kernel/audio/encoding/AudioEncodingService.h"
#include "../kernel/version/Version.h"
#include "libshout/LibShout.h"
#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


class NoiseStreamer : public Version, public NoiseStreamerNavigator
{
private:
	ILogService *logSrv;
	SignalService* sigSrv;
	AudioTagService *tagSrv;
    AudioEncodingService *encSrv;

    string configFilename;

	NoiseStreamerConfig* config;
	LibShout* libShout;
	PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;

	int numberOfPlayedTracks;

	void logNowPlaying(const PlaylistItem& item);

	void initializePlaylist();
	void initializeShout();

	void loadConfig();
	void loadPlaylist();
	void streamAudioFile(const PlaylistItem& item);
    void reEncodeAudioFile(PlaylistItem item);

	static void onLibShoutError(void* sender, EventArgs* e);

public:
	NoiseStreamer(
        ILogService *logSrv,
        SignalService *sigSrv,
        AudioTagService *tagSrv,
        AudioEncodingService *encSrv,
        string configFilename);
	virtual ~NoiseStreamer();

	static const char* USER_AGENT;

	string agentVersion();

	int getNumberOfPlayedTracks();

	void action();

	void connectShout();
	void finilizeShout();

	void streamPlaylist();
	void stopPlaying();
	PlaylistItem nowPlaying();
	int remainingTrackTime();

	string getGenreStats();
	string getArtistStats();

};

#endif // NoiseStreamer_h__
