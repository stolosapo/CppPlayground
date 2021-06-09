#ifndef AudioMetadataChangedEventArgs_h__
#define AudioMetadataChangedEventArgs_h__

#include <string>

#include "../../kernel/observer/EventArgs.h"

using namespace std;

class AudioMetadataChangedEventArgs: public EventArgs
{
private:
    string metadata;

public:
    AudioMetadataChangedEventArgs(string metadata);
    virtual ~AudioMetadataChangedEventArgs();

    string getMetadata();

};

#endif // AudioMetadataChangedEventArgs_h__
