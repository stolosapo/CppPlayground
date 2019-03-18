#ifndef NoiseStreamerHealth_h__
#define NoiseStreamerHealth_h__

class NoiseStreamerHealth
{
private:
    int shoutQueueLength;

protected:
    void setShoutQueueLenth(int queueLength);

public:
	NoiseStreamerHealth();
	virtual ~NoiseStreamerHealth();

    int getShoutQueueLength();

};

#endif // NoiseStreamerHealth_h__
