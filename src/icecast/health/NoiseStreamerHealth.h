#ifndef NoiseStreamerHealth_h__
#define NoiseStreamerHealth_h__

class NoiseStreamerHealth
{
private:
    static const int ERROR_THRESHOLD;

    int shoutQueueLength;
    int errorCounter;

protected:
    void setShoutQueueLenth(int queueLength);

    void incrementErrorCounter();
    void checkIfErrorCounterThresholdReached();
    void resetErrorCounter();

public:
	NoiseStreamerHealth();
	virtual ~NoiseStreamerHealth();

    int getShoutQueueLength();

};

#endif // NoiseStreamerHealth_h__
