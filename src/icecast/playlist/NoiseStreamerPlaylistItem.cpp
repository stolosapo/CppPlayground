#include "NoiseStreamerPlaylistItem.h"

#include "../../kernel/converter/Convert.h"
#include "../../kernel/utils/FileHelper.h"
#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/ExceptionMapper.h"


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

NoiseStreamerEncodeContext* NoiseStreamerPlaylistItem::getContext()
{
    return context;
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

void NoiseStreamerPlaylistItem::waitToFinishEncode()
{
    Thread* th = getEncodeThread();

    if (th == NULL)
    {
        return;
    }

    th->wait();
}

string NoiseStreamerPlaylistItem::reencode()
{
    ILogService* logSrv = context->getLogSrv();
    AudioEncodingService* encSrv = context->getEncSrv();

    string mp3InPath = track.getTrack();
    string pcmOutPath = context->getPcmOutPath();
    string mp3OutPath = context->getMp3OutPath();
    int threadPoolIndex = context->getEncodeThread()->getPoolIndex();
    string poolIndex = Convert<int>::NumberToString(threadPoolIndex);

    string pcmAudioFile = pcmOutPath + "pcm_audio_" + poolIndex + ".wav";
    string mp3AudioFile = mp3OutPath + "mp3_audio_" + poolIndex + ".mp3";

    logSrv->info("Start Re-Encoding.. '" + mp3InPath + "'");

	encSrv->decode(mp3InPath, pcmAudioFile);

    AudioEncodeMode encodeMode = context->getEncodeMode();
    AudioBitrate audioBitrate = context->getAudioBitrate();
    int samplerate = context->getSamplerate();
    int quality = context->getQuality();

    AudioTag* metadata = track.getMetadata();
    metadata->setReencodeData(encodeMode, audioBitrate, samplerate, quality);

	encSrv->encode(pcmAudioFile, mp3AudioFile, metadata);

    logSrv->info("End Re-Encoding.. '" + mp3InPath + "'");

    return mp3AudioFile;
}

void* NoiseStreamerPlaylistItem::encodeTrack(void* context)
{
    NoiseStreamerPlaylistItem* item = (NoiseStreamerPlaylistItem*) context;
    ILogService* logSrv = item->context->getLogSrv();

    try
    {

        string encodedFile = item->reencode();

        // Check if file is valid
        if (FileHelper::exists(encodedFile.c_str()))
        {
            item->encodedTrackFile = encodedFile;
        }
    }
    catch (DomainException& e)
	{
		logSrv->error(handle(e));
	}
    catch(RuntimeException& e)
	{
		logSrv->error(handle(e));
	}
	catch(exception& e)
	{
		logSrv->error(e.what());
	}

    return NULL;
}
