#include "SineWaveGenerator.h"

#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

SineWaveGenerator::SineWaveGenerator(SignalService *sigSrv):
    sigSrv(sigSrv)
{

}

SineWaveGenerator::~SineWaveGenerator()
{

}

void SineWaveGenerator::generate()
{
    for (int t = 0; ; t++)
    {
        if (sigSrv->gotSigInt())
        {
            break;
        }

        // pure middle C sine wave
        uint8_t temp = (sin(t * 2 * M_PI / R * C) + 1) * V;

        // middle C saw wave (bytebeat style)
        // uint8_t temp = t/F*C;

        // viznut bytebeat composition
        // uint8_t temp = (t*5&t>>7)|(t*3&t>>10);

        cout << temp;
    }
}
