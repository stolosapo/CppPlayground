#ifndef NoiseStreamerEncodeContext_h__
#define NoiseStreamerEncodeContext_h__

#include "../../kernel/audio/encoding/AudioEncodingService.h"
#include "../../kernel/task/Thread.h"

using namespace std;

class NoiseStreamerEncodeContext
{
private:
    Thread* encodeThread;
    AudioEncodingService* encSrv;
    string pcmOutPath;
    string mp3OutPath;

public:
    NoiseStreamerEncodeContext(Thread* encodeThread, AudioEncodingService* encSrv, string pcmOutPath, string mp3OutPath);
    virtual ~NoiseStreamerEncodeContext();

    Thread* getEncodeThread();
    AudioEncodingService* getEncSrv();
    string getPcmOutPath();
    string getMp3OutPath();
};

#endif // NoiseStreamerEncodeContext_h__
