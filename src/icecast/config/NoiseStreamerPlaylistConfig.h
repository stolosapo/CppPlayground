#ifndef NoiseStreamerPlaylistConfig_h__
#define NoiseStreamerPlaylistConfig_h__

#include <string>

#include "../../kernel/configuration/IConfig.h"
#include "../../kernel/audio/playlist/PlaylistStrategyType.h"
#include "../../kernel/audio/AudioBitrate.h"

using namespace std;

class NoiseStreamerPlaylistConfig : public IConfig
{
public:
    NoiseStreamerPlaylistConfig();
    virtual ~NoiseStreamerPlaylistConfig();

    static Model* factory();

    string getName();
    bool getDefault();
    string getPlaylist();
    string getHistory();
    string getMetadata();

    bool getRepeat();
    string getStrategy();
    PlaylistStrategyType getStrategyType();

protected:
    virtual void registerProperties();

};

#endif // NoiseStreamerPlaylistConfig_h__
