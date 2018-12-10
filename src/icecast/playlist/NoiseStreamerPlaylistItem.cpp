#include "NoiseStreamerPlaylistItem.h"


NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem()
    : track(PlaylistItem()), needEncode(false), encodeThread(NULL)
{

}

NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem(PlaylistItem track)
    : track(track), needEncode(false), encodeThread(NULL)
{

}

NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem(PlaylistItem track, Thread* encodeThread)
    : track(track), needEncode(true), encodedTrackFile(""), encodeThread(encodeThread)
{

}

NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem(const NoiseStreamerPlaylistItem& item)
{
    track = item.track;
    needEncode = item.needEncode;
    encodedTrackFile = item.encodedTrackFile;
    encodeThread = item.encodeThread;
}

NoiseStreamerPlaylistItem::~NoiseStreamerPlaylistItem()
{

}

PlaylistItem NoiseStreamerPlaylistItem::getTrack()
{
    return track;
}

Thread* NoiseStreamerPlaylistItem::getEncodeThread()
{
    return encodeThread;
}

string NoiseStreamerPlaylistItem::getTrackFile()
{
    if (needEncode)
    {
        return encodedTrackFile;
    }

    return track.getTrack();
}

bool NoiseStreamerPlaylistItem::readyToPlay()
{
    if (encodeThread == NULL)
    {
        return true;
    }

    return !encodeThread->isRunning();
}

void NoiseStreamerPlaylistItem::prepare()
{
    if (!needEncode)
    {
        return;
    }

    encodeThread->attachDelegate(encodeTrack);
    encodeThread->start(this, "runner: NoiseStreamerPlaylist, re-encode track");
}

void* NoiseStreamerPlaylistItem::encodeTrack(void* context)
{
    NoiseStreamerPlaylistItem* item = (NoiseStreamerPlaylistItem*) context;

    item->encodedTrackFile = "alek moi";

    return NULL;
}
