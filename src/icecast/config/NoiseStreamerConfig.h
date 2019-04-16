#ifndef NoiseStreamerConfig_h__
#define NoiseStreamerConfig_h__

#include <string>

#include "../../kernel/configuration/IConfig.h"
#include "../../kernel/audio/playlist/PlaylistStrategyType.h"
#include "../../kernel/audio/AudioBitrate.h"

using namespace std;

class NoiseStreamerConfig : public IConfig
{
public:
	NoiseStreamerConfig();
	virtual ~NoiseStreamerConfig();

	static Model* factory();

	string getHostname();
	string getPort();
	string getUsername();
	string getPassword();
	string getProtocol();
	string getMountpoint();
	string getName();
	string getGenre();
	string getDescription();
	string getUrl();
	string getPublic();
	string getBitrate();
	AudioBitrate getTypedBitrate();
	string getSamplerate();
	string getChannels();

	string getPlaylist();
	string getHistory();
	string getMetadata();

	bool getRepeat();
	string getStrategy();
	PlaylistStrategyType getStrategyType();

    bool getReencode();
    string getPcmOutPath();
    string getMp3OutPath();

    string getCommonTrackFilePrefix();

protected:
	virtual void registerProperties();

};

#endif // NoiseStreamerConfig_h__
