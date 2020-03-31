#ifndef SineWaveGenerator_h__
#define SineWaveGenerator_h__

#include "../../../interruption/SignalService.h"

class SineWaveGenerator
{
private:
    // sample rate (samples per second)
    const double R = 8000;

    // frequency of middle-C (hertz)
    const double C = 261.625565;

    // bytebeat frequency of 1*t due to 8-bit truncation (hertz)
    const double F = R / 256;

    // a volume constant
    const double V = 127;

    SignalService* sigSrv;

public:
	SineWaveGenerator(SignalService *sigSrv);
	virtual ~SineWaveGenerator();

    void generate();
};

#endif // SineWaveGenerator_h__
