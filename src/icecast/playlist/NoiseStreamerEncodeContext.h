#ifndef NoiseStreamerEncodeContext_h__
#define NoiseStreamerEncodeContext_h__

#include "../../kernel/log/ILogService.h"
#include "../../kernel/audio/encoding/AudioEncodingService.h"
#include "../../kernel/audio/encoding/AudioEncodeMode.h"
#include "../../kernel/audio/AudioBitrate.h"
#include "../../kernel/task/Thread.h"

using namespace std;

class NoiseStreamerEncodeContext
{
private:
    Thread* encodeThread;
    AudioEncodingService* encSrv;
    ILogService* logSrv;

    string pcmOutPath;
    string mp3OutPath;

    AudioEncodeMode encodeMode;
    AudioBitrate audioBitrate;
    int samplerate;
    int quality;

public:
    NoiseStreamerEncodeContext(
        Thread* encodeThread,
        AudioEncodingService* encSrv,
        ILogService* logSrv,
        string pcmOutPath,
        string mp3OutPath,
        AudioEncodeMode encodeMode,
        AudioBitrate audioBitrate,
        int samplerate,
        int quality);
    virtual ~NoiseStreamerEncodeContext();

    Thread* getEncodeThread();
    AudioEncodingService* getEncSrv();
    ILogService* getLogSrv();

    string getPcmOutPath();
    string getMp3OutPath();

    AudioEncodeMode getEncodeMode();
    AudioBitrate getAudioBitrate();
    int getSamplerate();
    int getQuality();
};

#endif // NoiseStreamerEncodeContext_h__
