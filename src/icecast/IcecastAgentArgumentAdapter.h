#ifndef IcecastAgentArgumentAdapter_h__
#define IcecastAgentArgumentAdapter_h__

#include <string>

#include "../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class IcecastAgentArgumentAdapter: public ArgumentAdapter
{
private:
    static const string CONFIG_FILE;

public:
	IcecastAgentArgumentAdapter(ArgumentService* argService);
	virtual ~IcecastAgentArgumentAdapter();

    virtual void registerArguments();

protected:
    virtual string title();

    bool hasAgentConfigFilename() const;
    string getAgentConfigFilename() const;

};

#endif // IcecastAgentArgumentAdapter_h__
