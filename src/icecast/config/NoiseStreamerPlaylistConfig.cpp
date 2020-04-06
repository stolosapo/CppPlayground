#include "NoiseStreamerPlaylistConfig.h"

#include "../../kernel/audio/AudioBitrateConverter.h"
#include "../../kernel/converter/Convert.h"


NoiseStreamerPlaylistConfig::NoiseStreamerPlaylistConfig() : IConfig(&factory)
{
    this->registerProperties();
}

NoiseStreamerPlaylistConfig::~NoiseStreamerPlaylistConfig()
{

}

void NoiseStreamerPlaylistConfig::registerProperties()
{
    registerPropertyName(1, "name", STRING);
    registerPropertyName(2, "default", BOOL);
    registerPropertyName(3, "playlist", STRING);
    registerPropertyName(4, "history", STRING);
    registerPropertyName(5, "metadata", STRING);
    registerPropertyName(6, "repeat", BOOL);
    registerPropertyName(7, "strategy", STRING);
}

Model* NoiseStreamerPlaylistConfig::factory()
{
    return (Model*) new NoiseStreamerPlaylistConfig;
}

string NoiseStreamerPlaylistConfig::getName()
{
    return getStringProperty("name");
}

bool NoiseStreamerPlaylistConfig::getDefault()
{
    return getBoolProperty("default");
}

string NoiseStreamerPlaylistConfig::getPlaylist()
{
    return getStringProperty("playlist");
}

string NoiseStreamerPlaylistConfig::getHistory()
{
    return getStringProperty("history", "playlist.history.pls");
}
string NoiseStreamerPlaylistConfig::getMetadata()
{
    return getStringProperty("metadata", "playlist.metadata.json");
}

bool NoiseStreamerPlaylistConfig::getRepeat()
{
    return getBoolProperty("repeat");
}

string NoiseStreamerPlaylistConfig::getStrategy()
{
    return getStringProperty("strategy", "");
}

PlaylistStrategyType NoiseStreamerPlaylistConfig::getStrategyType()
{
    string strategy = getStrategy();

    if (strategy == "SIMPLE")
    {
        return SIMPLE;
    }

    if (strategy == "RANDOM")
    {
        return RANDOM;
    }

    if (strategy == "RANDOM_ONCE")
    {
        return RANDOM_ONCE;
    }

    return NONE;
}
