#include "NoiseStreamerPlaylistItem.h"

#include "../../kernel/utils/FileHelper.h"


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

string NoiseStreamerPlaylistItem::reencode()
{
    if (context == NULL)
    {
        /* TODO: Log Warning!!! */
        return "";
    }

    string pcmOutPath = context->getPcmOutPath();
    string mp3OutPath = context->getMp3OutPath();
    string threadId = context->getEncodeThread()->getStringId();

    string pcmAudioFile = pcmOutPath + "pcm_audio_" + threadId + ".wav";
    string mp3AudioFile = mp3OutPath + "mp3_audio_" + threadId + ".mp3";

    cout << "Start Decoding.." << endl;
	context->getEncSrv()->decode(track.getTrack(), pcmAudioFile);
    cout << "End Decoding.." << endl;

    AudioEncodeMode encodeMode = context->getEncodeMode();
    AudioBitrate audioBitrate = context->getAudioBitrate();
    int samplerate = context->getSamplerate();
    int quality = context->getQuality();

    AudioTag* metadata = track.getMetadata();
    metadata->setReencodeData(encodeMode, audioBitrate, samplerate, quality);

    cout << "Start Re-Encoding.." << endl;
	context->getEncSrv()->encode(pcmAudioFile, mp3AudioFile, metadata);
    cout << "End Re-Encoding.." << endl;

    return mp3AudioFile;
}

void* NoiseStreamerPlaylistItem::encodeTrack(void* context)
{
    NoiseStreamerPlaylistItem* item = (NoiseStreamerPlaylistItem*) context;

    string encodedFile = item->reencode();

    // Check if file is valid
    if (FileHelper::exists(encodedFile.c_str()))
    {
        item->encodedTrackFile = encodedFile;
    }

    return NULL;
}
