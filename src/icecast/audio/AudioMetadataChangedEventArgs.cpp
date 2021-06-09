#include "AudioMetadataChangedEventArgs.h"

AudioMetadataChangedEventArgs::AudioMetadataChangedEventArgs(string metadata)
    : metadata(metadata)
{

}

AudioMetadataChangedEventArgs::~AudioMetadataChangedEventArgs()
{

}

string AudioMetadataChangedEventArgs::getMetadata()
{
    return metadata;
}
