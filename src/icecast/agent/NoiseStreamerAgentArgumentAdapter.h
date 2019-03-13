#ifndef NoiseStreamerAgentArgumentAdapter_h__
#define NoiseStreamerAgentArgumentAdapter_h__

#include <string>

#include "../../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class NoiseStreamerAgentArgumentAdapter: public ArgumentAdapter
{
private:
    static const string CONFIG_FILE;

public:
	NoiseStreamerAgentArgumentAdapter(ArgumentService* argService);
	virtual ~NoiseStreamerAgentArgumentAdapter();

    virtual void registerArguments();

protected:
    virtual string title();

    bool hasAgentConfigFilename() const;
    string getAgentConfigFilename() const;

};

#endif // NoiseStreamerAgentArgumentAdapter_h__
