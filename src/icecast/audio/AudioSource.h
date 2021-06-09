#ifndef AudioSource_h__
#define AudioSource_h__

#include <string>

#include "AudioSourceType.h"
#include "AudioSourceControls.h"
#include "AudioSourceConfig.h"
#include "../../kernel/observer/Event.h"

using namespace std;

class AudioSource: public AudioSourceControls
{
protected:
    ILogService* logSrv;
    SignalService* sigSrv;

    const AudioSourceType type;

public:
    Event OnError;
    Event OnAudioMetadataChanged;

    AudioSource(
        ILogService* logSrv,
        SignalService *sigSrv,
        const AudioSourceType type);
    virtual ~AudioSource();

    AudioSourceType getType() const;

    void shutdownAudioSource();

    virtual void initialize(AudioSourceConfig config) = 0;

    virtual int readNextMp3Data(unsigned char* mp3OutBuffer, size_t buffer_size) = 0;

};

#endif // AudioSource_h__
