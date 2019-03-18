#ifndef NoiseStreamerAgentClientArgumentAdapter_h__
#define NoiseStreamerAgentClientArgumentAdapter_h__

#include <string>

#include "../../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class NoiseStreamerAgentClientArgumentAdapter: public ArgumentAdapter
{
private:
    static const string CONFIG_FILE;

public:
	NoiseStreamerAgentClientArgumentAdapter(ArgumentService* argService);
	virtual ~NoiseStreamerAgentClientArgumentAdapter();

    virtual void registerArguments();

protected:
    virtual string title();

    bool hasAgentClientConfigFilename() const;
    string getAgentClientConfigFilename() const;

};

#endif // NoiseStreamerAgentClientArgumentAdapter_h__
