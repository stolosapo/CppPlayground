#include "NoiseStreamerPlaylistItem.h"


NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem(PlaylistItem track)
    : track(track), needEncode(false), context(NULL)
{

}

NoiseStreamerPlaylistItem::NoiseStreamerPlaylistItem(PlaylistItem track, NoiseStreamerEncodeContext* context)
    : track(track), needEncode(true), encodedTrackFile(""), context(context)
{

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
    if (context == NULL)
    {
        return NULL;
    }

    return context->getEncodeThread();
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
    Thread* th = getEncodeThread();

    if (th == NULL)
    {
        return true;
    }

    return !th->isRunning();
}

void NoiseStreamerPlaylistItem::prepare()
{
    if (!needEncode)
    {
        return;
    }

    Thread* th = getEncodeThread();

    if (th == NULL)
    {
        return;
    }

    th->attachDelegate(&encodeTrack);
    th->start(this, "runner: NoiseStreamerPlaylist, re-encode track");
}

void NoiseStreamerPlaylistItem::reencode()
{
    // cout << "Start Decoding.." << endl;
	// encSrv->decode(item.getTrack(), "audio.wav");
    // cout << "End Decoding.." << endl;
    //
    // int samplerate = Convert<int>::StringToNumber(config->getSamplerate());
    // AudioTag* metadata = item.getMetadata();
    // metadata->setReencodeData(VBR, BR_16kbps, samplerate, 3);
    //
    // cout << "Start Re-Encoding.." << endl;
	// encSrv->encode("audio.wav", "audio.mp3", metadata);
    // cout << "End Re-Encoding.." << endl;
}

void* NoiseStreamerPlaylistItem::encodeTrack(void* context)
{
    NoiseStreamerPlaylistItem* item = (NoiseStreamerPlaylistItem*) context;
    NoiseStreamerEncodeContext* encContext = item->context;
    string pcmOutPath = encContext->getPcmOutPath();
    string mp3OutPath = encContext->getMp3OutPath();

    item->encodedTrackFile = "alek moi";

    return NULL;
}
