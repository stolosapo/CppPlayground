#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "../kernel/log/ILogService.h"
#include "../kernel/interruption/SignalService.h"
#include "../kernel/audio/AudioTagService.h"
#include "../kernel/version/Version.h"
#include "libshout/LibShout.h"
#include "../kernel/audio/playlist/PlaylistHandlerFactory.h"


class IcecastClient : public Version
{
private:
	ILogService *logSrv;
	SignalService* sigSrv;
	AudioTagService *tagSrv;

	IcecastClientConfig* config;
	LibShout* libShout;
	PlaylistHandlerFactory* playlistHandlerFactory;
	PlaylistHandler* playlistHandler;

	int numberOfPlayedTracks;

	void logNowPlaying(PlaylistItem item);

	void initializePlaylist();
	void initializeShout();
	void finilizeShout();
	void connectShout();

	void loadConfig();
	void loadPlaylist();
	void streamPlaylist();

public:
	IcecastClient(ILogService *logSrv, SignalService *sigSrv, AudioTagService *tagSrv);
	virtual ~IcecastClient();

	static const char* USER_AGENT;

	static string agentVersion();

	int getNumberOfPlayedTracks();

	void action();

	void nextTrack();
	void stopPlaying();
	PlaylistItem nowPlaying();
	int remainingTrackTime();

	string getGenreStats();
	string getArtistStats();

};

#endif // IcecastClient_h__
