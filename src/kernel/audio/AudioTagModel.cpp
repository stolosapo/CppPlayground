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
        registerPropertyName(1, "title", STRING);
        registerPropertyName(2, "artist", STRING);
        registerPropertyName(3, "album", STRING);
        registerPropertyName(4, "comments", STRING);
        registerPropertyName(5, "genre", STRING);
        registerPropertyName(6, "year", INT);
        registerPropertyName(7, "track", INT);
        registerPropertyName(8, "duration", INT);
        registerPropertyName(9, "bitrate", INT);
        registerPropertyName(10, "samplerate", INT);
        registerPropertyName(11, "channels", INT);
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
