#include "AudioTagModel.h"

AudioTagModel::AudioTagModel() : Model(&factory)
{
        this->registerProperties();
}

AudioTagModel::AudioTagModel(AudioTag* tag) : Model(&factory)
{
        this->registerProperties();

        setStringProperty("title", tag->getTitle());
        setStringProperty("artist", tag->getArtist());
        setStringProperty("album", tag->getAlbum());
        setStringProperty("comments", tag->getComments());
        setStringProperty("genre", tag->getGenre());
        setIntProperty("year", tag->getYear());
        setIntProperty("track", tag->getTrack());
        setIntProperty("duration", tag->getDuration());
        setIntProperty("bitrate", tag->getBitrate());
        setIntProperty("samplerate", tag->getSamplerate());
        setIntProperty("channels", tag->getChannels());
}

AudioTagModel::~AudioTagModel()
{

}

Model* AudioTagModel::factory()
{
        return (Model*) new AudioTagModel();
}

void AudioTagModel::registerProperties()
{
        registerPropertyName(1, "title", Property::STRING);
        registerPropertyName(2, "artist", Property::STRING);
        registerPropertyName(3, "album", Property::STRING);
        registerPropertyName(4, "comments", Property::STRING);
        registerPropertyName(5, "genre", Property::STRING);
        registerPropertyName(6, "year", Property::INT);
        registerPropertyName(7, "track", Property::INT);
        registerPropertyName(8, "duration", Property::INT);
        registerPropertyName(9, "bitrate", Property::INT);
        registerPropertyName(10, "samplerate", Property::INT);
        registerPropertyName(11, "channels", Property::INT);
}

string AudioTagModel::getTitle()
{
        return getStringProperty("title", "");
}

string AudioTagModel::getArtist()
{
        return getStringProperty("artist", "");
}

string AudioTagModel::getAlbum()
{
        return getStringProperty("album", "");
}

string AudioTagModel::getComments()
{
        return getStringProperty("comments", "");
}

string AudioTagModel::getGenre()
{
        return getStringProperty("genre", "");
}

int AudioTagModel::getYear()
{
        return getIntProperty("year", 0);
}

int AudioTagModel::getTrack()
{
        return getIntProperty("track", 0);
}

int AudioTagModel::getDuration()
{
        return getIntProperty("duration", 0);
}

int AudioTagModel::getBitrate()
{
        return getIntProperty("bitrate", 0);
}

int AudioTagModel::getSamplerate()
{
        return getIntProperty("samplerate", 0);
}

int AudioTagModel::getChannels()
{
        return getIntProperty("channels", 0);
}
